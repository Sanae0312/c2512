#!/bin/bash
nums=(11 12 13)
echo "number of numbers is ${#nums[@]}"
echo "First number is ${nums[0]}"
echo "First number is ${nums[1]}"
echo "First number is ${nums[2]}"

nums[0]=21
echo "first number is ${nums[0]}"
nums+=(14)
echo "number of numbers is ${#nums[@]}"
echo "Fourth number is ${nums[3]}"

for e in ${nums[@]}; do
	echo $e
done

for (( i=0;i<${#nums[@]};i++ )); do
	echo ${nums[i]}
done

