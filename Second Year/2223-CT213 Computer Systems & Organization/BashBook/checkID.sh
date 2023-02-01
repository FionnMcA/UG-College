
#checks for correct number of args
if [ $# -lt 1 ]; then	
	exit 1
else
	index=2
	#exits with code of given ID if it does not exist in the "database"
	for $id in "$@"; do
		if ! [ -d "$id" ]; then
			exit $index 
		else
			index=$((index + 1))
		fi
	done
fi

#returns 0 if all ID's are found
exit 0
