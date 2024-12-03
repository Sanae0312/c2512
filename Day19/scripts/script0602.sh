#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
i=$N
until [ ! $i -ge 1 ]; do
	echo -n "$i "
	i=$(( i - 1))
done
echo
