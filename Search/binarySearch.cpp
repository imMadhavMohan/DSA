#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int n, int val){    
    int l = 0, r = n-1, mid = 0;

    while(l<=r){
        mid = l+(r-l)/2;
        if(val>arr[mid])
          l = mid+1;
        if(val<arr[mid])
          r = mid-1;  
        if(val==arr[mid])
            return mid; // Found
    }
    return -1; // not found
}

int main(){
    int arr[] = {-3,-1,1,3,2,5,7,136}; // 5 6---5 6---3
    int n = sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr+n);
    cout<<"Index is: "<<binarySearch(arr, n, 136)<<" && element is: "<<arr[binarySearch(arr, n, 136)];
    return 0;
}