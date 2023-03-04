gcc -c stack_array.c
gcc -c stackDriver.c
gcc -o testArrStack cgStackDriver.o heap_usage.o stack_array.o
gcc -o testListStack cgStackDriver.o heap_usage.o stack_2.o linked_list.o
 .\testArrStack.exe large.csv