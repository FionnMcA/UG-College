retId=$1
id=$2

if [ $# -ne 2 ]; then
	exit 1
fi


#runs checkID which makes sure the user(s) exists so that program can be run
./checkID.sh $id > /dev/null
check=$?

if [ $check -eq 0 ]; then
	mapfile -t input < "$id"/wall.txt
	
	output=("start of file_")

	for i in "${input[@]}"; do
		output+="$i"_
	done

	output+="end of file"
	echo $output > "$retId"_pipe

	exit 0
elif [ $check -eq 2 ]; then
	echo "User does not exist"
	exit 2
fi
