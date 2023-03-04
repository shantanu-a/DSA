gcc -c stackDriver.c
gcc -c heap_usage.c

gcc -c stack_array.c
gcc -c stack_ll.c

# gcc -o runStackWithArray stackDriver.o stack_array.o heap_usage.o
# ./runStackWithArray

gcc -c linked_list.c

gcc -o runStackWithArray stackDriver.o stack_ll.o heap_usage.o
./runStackWithArray

rm -f *.o runStackWithArray