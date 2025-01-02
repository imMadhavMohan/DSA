#include <iostream>
#include <climits>
#include <stdio.h> // memset
#include <algorithm>
using namespace std;

// using Array
int rear = -1;

typedef struct {
    int prt;
    int val;
}Node;

void enQueue(Node Arr[], int val, int prt, int size){
    if(rear==size)
        return;    
    ++rear;
    Arr[rear].prt = prt;
    Arr[rear].val = val;    
}

void printQueue(Node Arr[]){
    if(rear==-1)
        return;
    for(int i=0;i<=rear;i++)
        // if(Arr[i].prt != -1)
            cout<<"Val is: "<<Arr[i].val<<" & Prt is: "<<Arr[i].prt<<endl;
    cout<<endl;
}

void deQueue(Node Arr[]){
    if(rear==-1)
        return;
    int maxPrt = INT_MIN;
    int idx = -1;
    for(int i=0;i<=rear;i++)
        if(maxPrt<Arr[i].prt){
            maxPrt = Arr[i].prt;
            idx = i;
        }
    cout<<"deQueued atom(Val, Prt): "<<Arr[idx].val<<", "<<Arr[idx].prt<<endl;
    for(int i=idx;i<rear;i++){
        Arr[i].prt = Arr[i+1].prt;
        Arr[i].val = Arr[i+1].val;
    }
    rear--;
}

void peek(Node Arr[]){
    if(rear==-1) 
       return;
    int maxPrt = INT_MIN;
    int idx = -1;
    for(int i=0;i<=rear;i++)
        if(maxPrt<Arr[i].prt){
            maxPrt = Arr[i].prt;
            idx = i;
        }
    cout<<"Peeked atom(Val, Prt): "<<Arr[idx].val<<", "<<Arr[idx].prt<<endl; 
}

int main(){
    Node Arr[5];
    enQueue(Arr, 2, 1, 5); // enQueue(Node Arr[], int val, int prt, int size)
    enQueue(Arr, 1, 3, 5);
    enQueue(Arr, 3, 2, 5);
    enQueue(Arr, 5, 4, 5);
    enQueue(Arr, 4, 5, 5);

    printQueue(Arr);

    deQueue(Arr);
    deQueue(Arr);
    deQueue(Arr);

    printQueue(Arr);

    enQueue(Arr, 4, 6, 5); // enQueue(Node Arr[], int val, int prt, int size)
    enQueue(Arr, 5, 8, 5);

    printQueue(Arr);
    peek(Arr);
    return 0;
}