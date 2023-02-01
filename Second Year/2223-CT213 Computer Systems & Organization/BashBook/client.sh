id=$1

if [ $# -ne 1 ]; then
	echo "error: this script requires one id as a parameter"
	exit 1
fi 

#check if the id exists and runs create user if it doesn't already
./checkIDs.sh $id > /dev/null 
if [ $? -ne 0 ]; then
	./createUser.sh $id 
fi


if ! [ -e server ]; then	#if server isn't running
	./server.sh &
	echo "started server"
fi

#creates a pipe for the user's ID
mkfifo "$id"_pipe

echo "********bashbook********"

while true; do
	read -p "enter a command: (add | create | display | post" req
	echo $id $req > ./server
	read ret < "$id"_pipe	

	(echo "$ret" | grep "^nok:") > /dev/null
	error=$?
	(echo "$ret" | grep "^start of file") > /dev/null
	wall=$?

	if [ $error -eq 0 ];then
		output=$(echo $ret | sed "s/nok: /error: /")
		echo $output	
	
	elif [ $wall -eq 0 ]; then
		IFS='_' read -ra out <<< "$ret"
		
		# print all except first and last lines
		length=${#out[@]}
		for (( i=1; i<length-1; i++ )); do			
			printf '%s\n' "${out[$i]}"
			
		done
	else
		output=$(echo $ret | sed "s/ok: //")
		echo $output
	fi

done
