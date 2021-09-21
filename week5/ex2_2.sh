if ln ex2.txt ex2.txt.lock; then
	while true
	do
	    printf "\n$(($(tail -n 1 ex2.txt) + 1))" >> ex2.txt
	done
    rm ex2.txt.lock
fi