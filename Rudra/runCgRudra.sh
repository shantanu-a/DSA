gcc -c cgStackDriver.c
gcc -c heap_usage.c
gcc -c stack_array.c

gcc -o runCgRudra cgStackDriver.o stack_array.o heap_usage.o
./runCgRudra large.csv

gcc -c linked_list.c
gcc -c stack_2.c

gcc -o runCgRudra cgStackDriver.o stack_2.o heap_usage.o linked_list.o
./runCgRudra large.csv



#rm -f *.o runCgRudra