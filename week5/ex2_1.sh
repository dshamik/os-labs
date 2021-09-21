while true
do
printf "\n$(($(tail -n 1 ex2.txt) + 1))" >> ex2.txt
done