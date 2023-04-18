gcc -c linkedlist.c
gcc -c linkedlisttest.c

gcc -o q1 linkedlist.o linkedlisttest.o
./q1
rm -f *.o q1