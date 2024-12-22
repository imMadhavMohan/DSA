#include <iostream>
using namespace std;

bool linearSearch(int *arr, int n, int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val)
            return true;
    }
    return false;
}

int main(){
    int arr[] = {-1,-3,136,1,3,2,5,7}; // 5 6---5 6---3
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<linearSearch(arr, n, 136)?"Found\n":"Not found\n";
    return 0;
}