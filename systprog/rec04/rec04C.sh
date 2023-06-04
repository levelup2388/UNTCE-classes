#!/bin/bash
let num=(1+ $RANDOM %10)
echo $num
read -p"Enter a number between 1 and 10:" input
while [[ $input -ne $num ]];do
	if [[ $input -ne $num ]];then
		echo "Sorry, you are not correct. Try again!"
	fi
	read -p"Enter a number between 1 and 10:" input
	if [[ $input -eq $num ]];then
		break
	fi
done
if [ $input -eq $num ]
then
	echo "Congratulations, the number is $num."
fi

