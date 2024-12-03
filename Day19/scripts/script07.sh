#!/bin/bash
read -p "Enter month number:" month_number

case $month_number in
	1)
		month_name="January"
		;;
	2)
		month_name="February"
		;;
	3)
		month_name="March"
		;;
	4)
		month_name="April"
		;;
	*)
		echo "Invalid month number"
		exit1
		;;
	esac

	echo "Month name of month $month_number is $month_name."
