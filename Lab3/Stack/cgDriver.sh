gcc -c cgStackDriver.c
gcc -c heap_usage.c
gcc -c stack_array.c
gcc -c stack_ll.c



gcc -o cgDriver cgStackDriver.o stack_array.o heap_usage.o
./cgDriver

gcc -o cgDriver cgStackDriver.o stack_ll.o heap_usage.o
./cgDriver

rm -f *.o cgDriver