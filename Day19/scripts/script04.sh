#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
for i in $(seq 1 $N); do
	echo -n " $i"
done
echo
