gcc -c stackDriver.c
gcc -c heap_usage.c

gcc -c stack_2.c
gcc -c linked_list.c

gcc -o runRudra1 stackDriver.o stack_2.o heap_usage.o linked_list.o
./runRudra1