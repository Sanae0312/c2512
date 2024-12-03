#!/bin/bash
read -p "Enter number:" number
#tenPercent=$(( (number / 100) * 10))
#newNumber=$(( number + tenPercent))
#tenPercent=$(expr $num / 100 \* 10)
#newNumber=$(expr $number + $tenPercent)
let tenPercent=number/100*10
let newNumber=number+tenPercent
echo "10% raised number of $number is $newNumber."
