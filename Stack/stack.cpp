#include <iostream>
#include <climits>
#include <stdio.h> // memset
#include <algorithm>
using namespace std;

int top=-1;

void peek(int stk[]){
    if(top==-1)
        return;
    cout<<"Peked atom: "<<stk[top]<<endl;
}

void push(int stk[], int size, int val){
    if(top==size)        
      return;
    stk[++top] = val;
}

void printStk(int stk[]){
    if(top==-1)
        return;
    for(int i=0; i<=top; ++i)
        cout<<stk[i]<<" ";
    cout<<endl;
}

void pop(){
    if(top==-1)        
      return;
    top--;
}

int main(){
    int stk[5];
    push(stk,5,2);
    push(stk,5,1);
    push(stk,5,4);
    push(stk,5,3);

    printStk(stk);
    pop();
    pop();
    printStk(stk);

    return 0;
}