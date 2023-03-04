gcc -c stackDriver.c
gcc -c heap_usage.c
gcc -c stack_array.c

gcc -o runRudra stackDriver.o stack_array.o heap_usage.o
./runRudra