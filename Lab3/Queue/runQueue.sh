gcc -c queueDriver.c
gcc -c heap_usage.c
gcc -c queue_array.c


gcc -o runQueue queue_array.o queueDriver.o heap_usage.o
./runQueue

gcc -c queueDriver.c
gcc -c linked_list.c
gcc -c queue_ll.c

gcc -o runQueue queue_ll.o queueDriver.o heap_usage.o linked_list.o
./runQueue

rm -f *.o runQueue
