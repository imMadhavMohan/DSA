// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

/*
Heap is like Pyramid or heap of apples always the max one is kept at the top & removed 1st
    2: 0
1: 1     4: 2

    1: 0
2: 1     4: 2
*/

void heapify(int* arr, int i, int size){ // starting from bottom to top        
    int l = 2*i+1; // Left
    int r = 2*i+2; // Right
    int parent = i;

    if(l<size && arr[parent]>arr[l]) // left is bigger than parent
        parent = l;

    if(r<size && arr[parent]>arr[r]) // right is bigger than parent
        parent = r;    

    // if largest isn't root
    if(parent!=i){ // 
        swap(arr[parent],arr[i]);
        heapify(arr, parent, size);
    }    
}

void buildHeap(int* arr, int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(arr, i, n); // start from the last non-leaf node & move upward    
}

void printHeap(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printBinaryTree(int *arr, int n){
    if(n&1){ // Odd num of nodes (full binary tree)
        for(int i = 0; i < n/2;i++){        
            cout<<"Parent is:  "<<arr[i]<<" ";
            cout<<"L child:  "<<arr[2*i+1]<<" | "<<"R child:  "<<arr[2*i+2]<<'\n';
        }        
    }
    else{ // Even num of nodes
        for(int i = 0; i < n/2;i++){ 
            if(i!=(n/2)-1){       
                cout<<"Parent is:  "<<arr[i]<<" ";
                cout<<"L child:  "<<arr[2*i+1]<<" | "<<"R child:  "<<arr[2*i+2]<<'\n';
            }else{
                cout<<"Parent is:  "<<arr[i]<<" ";
                cout<<"L child:  "<<arr[2*i+1]<<" | "<<"R child:  "<<'\n';
            }
        }        
    }
}

int main(){
    int arr[] = {10, 2, 4, 3, 123, 10, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildHeap(arr, n); // Min heap
    printHeap(arr, n);
    printBinaryTree(arr, n);
    return 0;
}