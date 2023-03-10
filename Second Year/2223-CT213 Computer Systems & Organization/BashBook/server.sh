trap "rm server" EXIT


#creates the server pipe
mkfifo server

while true; do
	#gets command for server
	read id request friendID other < server
	#check what the command is and run the according script
	case $request in 
		add)
			if ! [ "$friendID" = '' ]; then 
				./add_friend.sh "$id" "$friendID"
				check=$?

				if [ $check -eq 1 ]; then
			 		echo "nok: friend already added" > "$id"_pipe
				elif [ $check -eq 3 ]; then
					echo "nok: user $friend doesn't exist" > "$id"_pipe
				else		
					echo "ok: friend $friendID added" > "$id"_pipe
				fi	
			else
				echo "nok: specify the friend ID" > "$id"_pipe
			fi
			;;
		post)
				if ! { [ "$friendID" = '' ] || [ "$other" = '' ]; }; then
					./post_messages.sh "$id" "$friendID" "$other"
					check=$?

					
				        if [ $check -eq 2 ]; then
				 	       echo "nok: receiver $friendID does not exist"
			       		else
			 			echo "ok: message posted" > "$id"_pipe
					fi
				else
					echo "nok: enter the friend ID followed by the message in quotes" > "$id"_pipe
				fi
			;;
		display)
			if ! [ "$friendID" = '' ]; then
				./display_wall.sh "$id" "$friendID"
				check=$?
				
				if [ $check -eq 2 ]; then
					echo "nok: user $friendID does not exist" > "$id"_pipe
				fi
			else
                        	echo "nok: enter the friend ID" > "$id"_pipe
                        fi

			;;
		exit)
			echo "exited" > "$id"_pipe
			exit 0	
			;;
		*)
			echo "only valid commands are add [friend ID] | post [friend ID] [message] | display [friend ID] or exit" > "$id"_pipe
			;;
	esac
done
