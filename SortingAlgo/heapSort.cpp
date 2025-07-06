// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int *arr, int i, int size){
    int parent = i; // max should be parent
    int l = 2*parent+1;
    int r = 2*parent+2;

    if(l<size && arr[parent]<arr[l])
        parent = l;
    if(r<size && arr[parent]<arr[r])
        parent = r;
    
    if(parent != i){
        swap(arr[parent], arr[i]); // rearrange parent
        heapify(arr, parent, size); // Recursively heapify the affected subtree
    }    
}

void buildHeap(int* arr, int n){
    for(int i=n/2-1;i>=0;i--) //last non-leaf node & so on
        heapify(arr, i, n);    
}

void printHeap(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void heapDelete(int *arr, int n){
    swap(arr[0], arr[n-1]); // swap largest element with the last element
    buildHeap(arr, n-1); // Rearrange heap & heapify
}

int main(){
    int arr[] = {10, 2, 4, 3, 123, 10, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildHeap(arr, n);
    printHeap(arr, n);    

    // Actual sorting by deletion & keeping largest atom at last
    for(int i=n;i>0;i--)
        heapDelete(arr, i); // reducing size of heap after deletion
        
    printHeap(arr, n);   
    return 0;
}