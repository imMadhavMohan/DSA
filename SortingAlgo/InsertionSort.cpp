#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 and arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArr(int *arr, int n){
    for(int i =0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {-1,-3,136,1,3,2,5,7}; // 5 6---5 6---3
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printArr(arr, n);
    return 0;
}