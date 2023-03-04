#include<stdio.h>
#include<stdlib.h>
#include "stack_ll.c"
#include "linked_list.h"

void qs_iter_attemp2(int ls[], int lo, int hi)
{
    Stack *s = newStack();
    Element ele = {lo, hi};
    push(s, ele);
    while (!isEmpty(s)){
        Element e = *top(s);
        pop(s);
        lo = e.lo;
        hi = e.hi;
        while (lo < hi){
            for(int i=0;i<4;i++){
                printf("%d\t",ls[i]);
            }
            printf("\n");
            int p = pivot(ls, lo, hi);
            p = part(ls, lo, hi, p);
            push(s, (Element){lo, p - 1});
            lo = p + 1;
            }
    }
}

int main(){
    int A[]={7,3,1,6,8};
    qs_iter_attemp2(A,0,4);
}