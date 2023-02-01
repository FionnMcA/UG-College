#for synchronisation
if [ -z "$1" ]; then
	exit 1
else
	while ! ln -s "$1" "$2" 2> /dev/null; do
		echo "$1 Locked"
		sleep 1
	done

	exit 0
fi

