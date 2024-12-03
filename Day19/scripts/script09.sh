#!/bin/bash
read -p "Enter the week name: " week_name

case $week_name in
	"Monday")
		week_number=1
		;;
	"Tuesday")
		week_number=2
		;;
	"Wednesday")
		week_number=3
		;;
	"Thursday")
		week_number=4
		;;
	"Friday")
		week_number=5
		;;
	"Saturday")
		week_number=6
		;;
	"Sunday")
		week_number=7
		;;
	*)
		echo "Invalid week name"
		exit 1
		;;
esac

echo "Week number of week $week_name is $week_number"

