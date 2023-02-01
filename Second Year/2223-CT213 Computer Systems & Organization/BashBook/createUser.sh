user=$1
#for synchronisation
./acquire.sh "$user" "$user"lock
#runs checkID which makes sure the user(s) exists
./checkID.sh $user
# runs the command, then checks the exit code
check=$?

#check if the number of arguments is correct
if [ $# -ne 1 ]; then
	./release.sh "$user"lock
        exit 1
#if the user already exists 
elif [ $check -eq 0 ] ; then	
 	./release.sh "$user"lock
	exit 2
	#creates user directory / friends list / wall file
elif [ $check -eq 2 ]; then	
        mkdir $user			
	touch $user/friends.txt		
	touch $user/wall.txt	
	#for sunchronisation	
        ./release.sh "$user"lock
	exit 0
fi
