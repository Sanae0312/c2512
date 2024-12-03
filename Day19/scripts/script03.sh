#!/bin/bash
read -p "Enter first number:" number1
read -p "Enter second number:" number2
read -p "Enter third number:" number3

if [ $(( $number1 % 2 )) -eq 1 ]; then
	count=$(( $count + 1))
fi

if [ $(( $number2 % 2 )) -eq 1 ]; then
	count=$(( $count + 1))
fi

if [ $(( $number3 % 2 )) -eq 1 ]; then
	count=$(( $count + 1))
fi

echo there are $count odd numbers among $number1,$number2 and $number3
