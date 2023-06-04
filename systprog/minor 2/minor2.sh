#!/bin/bash
#nicholas Bright (nicholasbright@my.unt.edu)
eproto(){
	echo "(SIGINT) received"
	var="this"
	read -p"Terminate Program? (Y/N) " input
	if [[ $input == "y" || $input == "Y" ]];then
		let check=1
		echo "Terminating program"
		kill
	else
		echo "Continuing Execution"
	fi
}
trap 'eproto' 2

check=0
users=($@)
if [ $# -eq 0 ]; then
	users=($(ps aux|awk '{print $1}' |sort -u|egrep -v "USER|\-"|tr -s '\n'))
	numUser=($(ps aux| awk '{print $1}' |sort -u|egrep -v "USER|\-"|wc -l))
else
	users=($@)
	numUser=${#users[@]}
fi

while [ $check -ne 1 ];do
	numPro=0
	total=0
	date
	echo -e "User ID \t\t Count "
	for i in "${users[@]}"
	do
		numPro=$(ps aux |grep -v grep |awk '{print $1}' |grep ${i} |wc -l)
		echo -e "$i \t\t $numPro"

		let total=$(( $numPro + $total ))
	done
	echo "$numUser USERS, TOTAL PROCESSES $total"
	sleep 5
done
