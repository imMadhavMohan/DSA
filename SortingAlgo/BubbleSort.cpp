#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<n; j++){
           if(arr[i]>arr[j]){
               swap(arr[i], arr[j]);
           }
        }
    }
}

void printArr(int *arr, int n){
    for(int i =0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {-1,-3,136,1,3,2,5,7}; // 
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printArr(arr, n);
}
