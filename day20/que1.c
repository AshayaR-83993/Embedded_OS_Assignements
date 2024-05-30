//1. Implement fast ﬁle copy program (assume max ﬁle size = 1 GB).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>//to use open,read,write
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>

int main(int argc,char* argv[]){

struct stat st;
int fd1,fd2,ret,ftrunc_ret;
void *ptr1,*ptr2;

//step 1: open src ﬁle in rdonly mode.
	fd1 = open(argv[1],O_RDONLY);
	if(fd1<0){

		perror("open1() failed");
		_exit(1);

	}
	printf("file descriptor = %d\n",fd1);

//step 2: get size of src ﬁle (fstat() syscall)

	ret = fstat(fd1,&st);
	if(ret < 0){

		perror("fstat() failed");
		_exit(2);
	}

//step 3: map src ﬁle contents to memory using mmap()
	
	ptr1 = mmap(NULL,st.st_size,PROT_READ,MAP_PRIVATE,fd1,0);
	if(ptr1 == (void*)-1){

		perror("mmap1() failed");
		close(fd1);
		_exit(3);
	}
	printf("reading file size : %lu\n",st.st_size);

//step 4: create dest ﬁle in rdwr mode.

	fd2 = open(argv[2],O_CREAT | O_RDWR , 0660);
	if(fd2<0){
	
		perror("open2() failed");
		close(fd2);
		_exit(4);
	}

//step 5: make size of dest ﬁle, same as size of src ﬁle using ftruncate()

	ftrunc_ret = ftruncate(fd2,st.st_size);
	if(ftrunc_ret<0){

		perror("ftruncate() failed");
		_exit(5);
	}
//step 6: map dest ﬁle contents to memory using mmap() -- MAP_SHARED.
	
	ptr2 = mmap(NULL,st.st_size,PROT_WRITE | PROT_READ,MAP_SHARED,fd2,0);
	if(ptr2 == (void*)-1){

		perror("mmap2() failed");
		_exit(6);
	}
//step 7: copy src ﬁle to dest ﬁle using memcpy()

	void *memcpy_ret = memcpy(ptr2,ptr1,st.st_size);
//step 8: close src and dest ﬁles.
	
	write(1, ptr2, st.st_size);

	close(fd1);
	close(fd2);

	return 0;
}
