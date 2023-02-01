id=$1
friend=$2

#runs checkID which makes sure the user(s) exists
./checkID.sh $id $friend
check=$?	#check what the exit code was	

if [ $check -eq 0 ]; then
	./acquire.sh $id/friends.txt "$id"friendslock.txt
	if ! [ $id == $friend ]; then
		./acquire.sh $friend/friends.txt "$friend"friendslock.txt
	fi
	./checkFriends.sh $id $friend
	friends=$?
	if [ $friends -eq 1 ]; then
		#add name of the friend to the text file
		echo $friend >> $id/friends.txt	
		#add self to friend's friends.txt file too - seemed to make sense to make friendship symmetric
		echo $id >> $friend/friends.txt	
		#runs synchronisation
		./release.sh "$id"friendslock.txt
		./release.sh "$friend"friendslock.txt
		exit 0	#exit ok
	else
		#runs synchronisation
		./release.sh "$id"friendslock.txt
		./release.sh "$friend"friendslock.txt
		#friend already added
		exit 1	
	fi
elif [ $check -eq 2 ]; then
	#user doesn't exist
	exit 2 
elif [ $check -eq 3 ]; then
	#friend doesn't exist
	exit 3 
fi
