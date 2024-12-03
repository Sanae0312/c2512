#!/bin/bash
nums=()
read -p "Enter number of numbers: " size

for (( i=0;i<$size;i++ )); do
	read -p "Enter number: " num
	nums+=($num)
done

for (( i=0;i<${#nums[@]};i++)); do
	echo -n "${nums[i]} "
done 
echo
