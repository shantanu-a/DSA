#include<bits/stdc++.h>
//#include <stack>
using namespace std;

int main(){
    stack<int> stack;
    int arr[5]={6,3,4,5,3};
    int s[5];
    stack.push(arr[0]);
    s[0]=1;
    int count=1;

    for(int i=1;i<5;i++){
        if(arr[i]>stack.top())count++;      
        else count=1;
            
        s[i]=count;
        stack.push(arr[i]);
    }

    for(int i=0;i<5;i++) printf("%d\t",s[i]);
}