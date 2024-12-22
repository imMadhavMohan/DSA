#include <iostream>
using namespace std;

void merge(int *arr, int l, int mid, int h){
    int n1 = mid-l+1;
    int n2 = h-mid;
    int *larr = new int[n1]; // left arr
    int *rarr = new int[n2]; // left arr

    for(int i=0;i<n1;i++)
        larr[i] = arr[l+i]; // 3 1

    for(int i=0;i<n2;i++)
        rarr[i] = arr[mid+1+i]; // rest half: 3 5 4

    int i = 0, j = 0, k=l;
    // merge & compare
    while(i<n1 && j<n2){
        if(larr[i]<=rarr[j])
            arr[k] = larr[i++];
        else if(larr[i]>rarr[j])
            arr[k]  = rarr[j++];        
        k++;
    }

    while(i<n1)
        arr[k++] = larr[i++];
    
    while(j<n2)
        arr[k++] = rarr[j++];
}

void mergeSort(int *arr, int l, int h){
    if(l<h){
        int mid = l+(h-l)/2; // Divide arr, to avoid overflow use this expression
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);   
        merge(arr, l, mid, h);
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

    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}

/*
// 0   9   = 4, 5 9 = 7, 5,7 : 8,9
arr = {38, 27, 43, 10};
    38 27      43 10
    27, 38     10 43
    10 27      38 43
*/