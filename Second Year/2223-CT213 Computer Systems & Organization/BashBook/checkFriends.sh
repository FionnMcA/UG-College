user1=$1
user2=$2

#runs checkID which makes sure the user(s) exists
./checkID.sh $user1 $user2 > /dev/null
check=$?

if [ $check -ne 0 ];then
	#first check that all users exist
	exit 1	
fi

grep "^$user1$" "$user2"/friends.txt > /dev/null
exists=$?	
#search through user2's friends list
if [ $exists -eq 1 ]; then
	exit 1	
else
	exit 0
fi
