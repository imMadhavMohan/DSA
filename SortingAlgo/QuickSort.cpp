#include <iostream>
using namespace std;

int partition(int *arr, int l, int h){
    int pivot = arr[h];
    int idx = l-1; // virtual idx
    int j = l;

    while(j<h){
        if(arr[j]<= pivot){
            idx++;
            swap(arr[j], arr[idx]); //  [40, 10, 30] ~=  [10, 40, 30]
        }
        j++;
    }
    swap(arr[idx+1] , arr[h]); // Put pivot at correct location
    return idx+1; // return pivot index
}

void quickSort(int arr[], int l, int h){
     if(l<h){
        int p = partition(arr , l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h); // Don't disturb element at "pth pos"
     }
}

void printArr(int *arr, int n){
    for(int i =0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70}; // 5 6---5 6---3
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}

/*

Visualization Example
Suppose arr = [10, 80, 30, 90, 40, 50, 70] and the pivot is 70.

Initial:

css
Copy code
i = -1, j = 0 to 5
Pivot = 70
Iteration (j = 0 to 5):

When arr[j] <= pivot, increment i and swap arr[i] with arr[j]:
arr[j] = 10: i = 0, swap(10, 10) (no effect).
arr[j] = 30: i = 1, swap(30, 80) → [10, 30, 80, ...].
arr[j] = 40: i = 2, swap(40, 80) → [10, 30, 40, ...].
...
Final Swap:

After the loop, arr[i+1] (position for pivot) is swapped with the pivot:
swap(arr[i+1], pivot) ensures the pivot is in its correct position.


arr = [40, 10, 30]
css
Copy code
i = -1, j = 0 to 1
Pivot = 30
Iteration (j = 0 to 1):

*/