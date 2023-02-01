user="$1"
receiver="$2"
message="$3"

#runs checkID which makes sure the user(s) exists
./checkID.sh $sender $receiver
check=$?

if [ $check -eq 2 ]; then	
	#if user doesn't exist
	exit 1 
elif [ $check -eq 3 ]; then
	#receiver doesn't exist
	exit 2 
elif [ $check -eq 0 ]; then
	./checkFriends.sh $user $receiver > /dev/null
	friends=$?

	if [ $friends -ne 0 ];then
		#users are not in each others friend list
		exit 3 
	else 
		#synchronisation
		./acquire.sh $receiver/wall.txt "$receiver"walllock.txt
		echo "$user: $message" >> ./$receiver/wall.txt
		./release.sh "$receiver"walllock.txt
		exit 0
	fi
fi
