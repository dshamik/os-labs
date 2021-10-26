mkdir week01

echo "Dinar Shamsutdinov" > week01/file.txt

rm _ex2.txt
rm ex2.txt

link ./week01/file.txt ./_ex2.txt
find ./week01/file.txt -inum "$(ls -i week01/file.txt | cut -d" " -f1)" >> ./ex2.txt
find ./week01/file.txt -inum "$(ls -i week01/file.txt | cut -d" " -f1)" -exec rm {} \; >> ./ex2.txt