mkdir tmp

touch tmp/file1
touch tmp/file2

link tmp/file1 tmp/link1

touch tmp/file3

gcc ex4.c -o ex4
./ex4 > ex4.txt