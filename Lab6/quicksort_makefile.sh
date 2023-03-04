gcc -c heap_usage.c
gcc -c linked_list.c
gcc -c stack_ll.c
gcc -c quicksort_iterative.c

gcc -o quicksort_makefile quicksort_iterative.o stack_ll.o heap_usage.o linked_list.o
./quicksort_makefile

rm -f *.o quicksort_makefile