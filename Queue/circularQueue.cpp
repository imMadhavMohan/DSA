#include <iostream>
#include <stdio.h> // memset
#include <algorithm>
using namespace std;

int front = -1;
int rear  = -1;

void enQueue(int Queue[], int val, int size){       
    if ((rear + 1) % size == front) {
        cout << "Overflow\n";
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;    
    Queue[rear] = val;    
}

void deQueue(int size){
    if(front<0){
        cout<<"Queue * underflow\n";
        return ;
    }
    
    if(rear==front)
        rear = front = -1;  // "Queue # is empty\n";
    else 
        front = (front + 1) % size; // Move front forward circularly
}

void printQ(int *Queue, int size){
    if(front<0){
       cout<<"Nothing to print";   
       return;
    }
    int i = front;
    do{ // while i!=(rear+1)
        cout<<Queue[i]<<" "; // start print from the front & end on rear
        i = (i+1)%size; 
    }while(i!=(rear+1)%size); // we want circular rotation so never use "<=, >=" as rear < front or vice-versa
}

void peek(int *Queue){
    cout<<Queue[front]<<endl;
}

int main(){
    int n  = 9;
    int Queue[n];
    int size = sizeof(Queue)/sizeof(Queue[0]);
    for(int i=0;i<9;i++)
        enQueue(Queue, i+1, size);
    printQ(Queue, size);
    deQueue(size);
    deQueue(size);
    deQueue(size);
    cout<<"\nRear is: "<<rear<<'\n';
    cout<<"Front is: "<<front<<'\n';
    for(int i=9;i<12;i++)
        enQueue(Queue, i+1, size);
    peek(Queue);
    printQ(Queue, size);
    return 0;
}