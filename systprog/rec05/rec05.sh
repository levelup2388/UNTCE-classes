#!/bin/bash

curve()
{
incr=("$1")
shift
arr=("$@")
index=0
for i  in "${arr[@]}"
do
	let grades[$index]=($i+$incr)
	let index=$index+1
done
}
if [ $# -ne 1 ]; then
	echo "usage: ./rec05.sh <curve amount>"
else
for i in 1 2 3 4 5
do
	read -p"Enter QUIZ #$i:" grades[$i-1]
done
curve $1 "${grades[@]}"
echo "CurvedGrades:"
for (( i=0 ; $i<${#grades[*]}; i=$i+1 ))
do
	echo "grades[$i] = ${grades[$i]}"
done
fi
