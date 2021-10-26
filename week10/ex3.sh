rm ex3.txt

echo "Dinar Shamsutdinov" > _ex3.txt

chmod 666 _ex3.txt
ls -la _ex3.txt >> ex3.txt

chmod 707 _ex3.txt
ls -la _ex3.txt >> ex3.txt

chmod g=u _ex3.txt
ls -la _ex3.txt >> ex3.txt

echo "660 - owner: read, write; group: read, write; others: nothing" >> ex3.txt
echo "775 - owner: read, write, execute; group: read, write, execute; others: read, execute" >> ex3.txt
echo "777 - owner: read, write, execute; group: read, write, execute; others: read, write, execute" >> ex3.txt