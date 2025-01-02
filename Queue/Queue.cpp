// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <memory>
#include <string.h>
using namespace std;

/*
    FIFO: push & pop + seek;
*/
int front = -1, rear = -1;
int Qsize = 5;

void enQueue(int *Queue, int val){
    if(rear==Qsize)
        cout<<"Q is overflowed\n";
    else
        if(front==-1 and rear==-1){
            Queue[++front]=val;
            rear = front;
        }else
            Queue[++rear]=val;                   
}

void deQueue(){    
    if(front==-1 and rear==-1)
        cout<<"Q is underflowed\n";
    else
        if(front==rear)           
            front = rear = -1;            
        else
            front++;                
}

void printQ(int *Queue){
    if(front!=rear)
        for(int i=front;i<=rear;i++)
            cout<<Queue[i]<<" ";
    else 
        cout<<"Nothing to print";
    cout<<endl;
}

void peek(int *Queue){
    cout<<Queue[front]<<endl;
}

int main(){    
    int Queue[Qsize];
    memset(Queue, -1, sizeof(Queue));

    printQ(Queue);

    for(int i=0;i<Qsize;i++)
        enQueue(Queue, i+1);
                
    deQueue();
    printQ(Queue);
    peek(Queue);

    enQueue(Queue, 14);
    printQ(Queue);
    return 0;
}

