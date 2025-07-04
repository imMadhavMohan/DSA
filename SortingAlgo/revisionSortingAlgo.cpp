// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int *arr, int l, int mid, int h){
    int n1 = mid-l+1; //3 012345
    int n2 = h-mid; // 3
    int *larr = new int[n1];
    int *rarr = new int[n2];
    
    for(int i=0;i<n1;i++)
        larr[i] = arr[l+i];
    for(int j=0;j<n2;j++)
        rarr[j] = arr[mid+1+j];
        
    int i=0, j=0, k=l;
    while(i<n1 and j<n2){
        if(larr[i]<rarr[j])
            arr[k++] = larr[i++];
        else arr[k++] = rarr[j++];
    }
    while(j<n2)
        arr[k++] = rarr[j++];
            
    while(i<n1)
        arr[k++] = larr[i++];        
}

void mergeSort(int* arr, int l, int h){
    if(l<h){
        int mid = l+(h-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertSort(int arr[], int n){
    int j,key = 0; // 4 3
    for(int i=1;i<n;i++){
        j = i-1; key = arr[i];
        while(j>=0 and arr[j]>key){
            arr[j+1] = arr[j-1];
            j--;
        }
        arr[j+1] = key;
    }
}

// 3, 2, 1.idx, 9, 5, 8
int partition(int arr[], int l, int h){
    int pivot = arr[h]; 
    int idx = l-1; // consider l-1 as pivots virtual index
    
    for(int i=l;i<h;i++){
        if(arr[i]<=pivot){
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    // Place pivot at its correct position
    swap(arr[h], arr[idx+1]); // this case: when for loop doesn't modify anything: {vir: idx, 7, 4, 1, 3, 0, 6}
    return idx+1;
}

void quickSort(int *arr, int l, int h){
     if(l<h){
        int pivot = partition(arr,l,h);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, h); // Pivot is at correct place
    }
}

int main() {
    int arr[] = {10, 2, 4, 3, 123, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    
    insertSort(arr, n);
    printArr(arr, n);
    
    quickSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}