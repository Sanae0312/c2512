#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
i=1
until [ $i -gt $N ]; do
	echo -n "$i "
	i=$(( i + 1))
done
echo
