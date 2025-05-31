#include <iostream>
using namespace std;
/*
0+2, 1+2, 2+2 % 5 =, 3+2%5 = 0, 4+2%5 = 1,  k=2

optimize K=K%n; // K is too large
12345: 1st
51234
45123
34512
23451 : 5th, n = 5 size of Arr
12345 : 6th same as 1st
51234 : 7th same as 2nd

//Optimize solution
12345, k=2; 45123; Right rotation
54321, 1. rev arr
45321, 2. rev 0 - (k-1) first k atom
45123, 3. rev k - n-1

12345, k=2; 34512; Left rotation
21345, 1. rev arr 0 - (k-1), first k atom
21543, 2. rev k - n-1
34512, 3. rev arr
*/

void rotArr(int Arr[], int k, int n){ // O(n*k)
    for(int i=0;i<k;i++){
        int key = Arr[0];
        for(int i=0;i<n;i++)
            Arr[i] = Arr[i+1];        
        Arr[n-1] = key;
    }
}

void reverseArr(int arr[], int l, int h){
    // we can also use mid = l+(h-l)/2; while(i<=mid)
    while(l<h){ // break when l==h
        swap(arr[h], arr[l]);
        l++; h--;
    }
}

void rotArrRight(int arr[], int k, int n){ // O(n)
    reverseArr(arr, 0, n-1);
    reverseArr(arr, 0, k-1);
    reverseArr(arr, k, n-1);
}

void rotArrLeft(int arr[], int k, int n){ // O(n)    
    reverseArr(arr, 0, k-1);
    reverseArr(arr, k, n-1);
    reverseArr(arr, 0, n-1);
}

void printArr(int Arr[], int n){
    for(int i=0;i<n;i++)
        cout<<Arr[i]<<" ";    
    cout<<endl;    
}

int main(){
    int n=5;
    int arr[n] = {1,2,3,4,5};
    int k = 7%n; // 2 is remainder
    // rotArr(arr, k, 5); // O(n*k)
    // printArr(arr, 5);

    // rotArrRight(arr, k, n); // O(n)
    // printArr(arr, n);

    rotArrLeft(arr, k, n); // O(n)
    printArr(arr, n);
    return 0;
}