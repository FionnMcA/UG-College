#for synchronisation
if [ -z "$1" ]; then
	exit 1
else
	rm "$1"
	exit 0
fi
