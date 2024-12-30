// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

/*
Insert & Delete elements: O(log n)
HeapSort = O(n*log n) : n times removal & then heapify O(log n)
Build heap: O(n*log n)
        1
    2       3   
    // i: parent, left child: 2*i+1 & right child: 2*i+2 ; if i = 0.
    // & Parent of a Node: ith atom: |_ i/2 _| floor val
    Note: All levels are completely filled with nodes: Full Binary Tree & A full binary tree always a complete binary tree.
    Note: Arr: 2 3 _ _ 4 5 isn't a complete binary tree.
    Note: Arr: 2 3 5 6 4 15 isn a complete binary tree but not a full binary tree.
        2
    3        5
 6     4  15      
*/

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

    printBinaryTree(arr, n);

    return 0;
}