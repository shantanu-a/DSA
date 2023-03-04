#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int fibonacciR(int n){
    //printf("1\n");
    if(n==0)return 0;
    else if(n==1)return 1;
    return fibonacciR(n-1)+fibonacciR(n-2);
}

int fibonacciI(int n){
    //printf("2\n");
    if(n==0)return 0;
    else if(n==1)return 1;
    int i=0;
    int prev=0,prev2=0;
    int acc=0;

    while(i!=n+1){
        if(i==0){
            prev2=prev=0;
            acc=0;
        }
        else if(i==1){
            prev2=0;
            prev=1;
            acc=1;
        }
        else{
            acc=prev+prev2;
            prev2=prev;
            prev=acc;
        }
        i++;
    }
    return acc;
}

int main(){
    struct timeval t1,t2,t3,t4;
    double time_taken;

    gettimeofday(&t1,NULL);
    printf("%lld\t",fibonacciR(50));
    gettimeofday(&t2,NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("%lf\n",time_taken);

    gettimeofday(&t3,NULL);
    printf("%lld\t",fibonacciI(50));
    gettimeofday(&t4,NULL);

    time_taken = ((t4.tv_sec) - t3.tv_sec) * 1e6;
    time_taken = (time_taken + (t4.tv_usec - t3.tv_usec)) * 1e-6;
    printf("%lf\n",time_taken);

}