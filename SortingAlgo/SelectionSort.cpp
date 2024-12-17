#include <iostream>
using namespace std;
// we select a smallest num & place it at the beginning & so on continues to the
// remaining indexes of the array
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<min)
                swap(min , arr[j]);
        }
        arr[i] = min;
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

    selectionSort(arr, n);
    printArr(arr, n);
    return 0;
}