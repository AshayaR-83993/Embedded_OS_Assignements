#!/bash/bin

echo -n "enter a month and a year : "
read month year

a=`echo "$year%4" | bc`
b=`echo "$year%100" | bc`
c=`echo "$year%400" | bc`

case $month in 
1|jan|january)
		echo "$month has 31 days in $year"
		;;
2|feb|february)
		if [ $c -eq 0 ]
		then
				echo "$month has 29 days in $year"
		elif [ $a -eq 0 -a $b -ne 0 ]
		then
				echo "$month has 29 days in $year"
		else
				echo "$month has 28 days in $year"
		fi
		;;
3|mar|march)
		echo "$month has 31 days in $year"
		;;
4|apr|april)
		echo "$month has 30 days in $year"
		;;
5|may)
		echo "$month has 31 days in $year"
		;;
6|jun|june)
		echo "$month has 30 days in $year"
		;;
7|jul|july)
		echo "$month has 31 days in $year"
		;;
8|aug|august)
		echo "$month has 31 days in $year"
		;;
9|sep|september)
		echo "$month has 30 days in $year"
		;;
10|oct|october)
		echo "$month has 31 days in $year"
		;;
11|nov|november)
		echo "$month has 30 days in $year"
		;;
12|dec|december)
		echo "$month has 31 days in $year"
		;;
*)
		echo "invalid month"
esac
