#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
// 0, 1, 2, 0, 1, 2 // 0 1LM 1, 2, 0, 1, 2R
// 0 1L 1M 2 0 1 2R  // 0 1L 1 2M 0 1 2R // 0 1L 1 2M 0 1R 2
// 0 1L 1 1M 0R 2 2 // 0 1L 1 1 0MR 2 2 // 0 0 1L 1 1R 2M 2


void sortArr(vector<int> &arr){ 
    int l=0, m=0, r=arr.size()-1; 
    while (m <= r) {
        switch (arr[m]) {

        // If the element is 0
        case 0:
            swap(arr[l++], arr[m++]);
            break;

        // If the element is 1 .
        case 1:
            m++;
            break;

        // If the element is 2
        case 2:
            swap(arr[m], arr[r--]);
            break;
        }
    }
    for(auto x : arr)
        cout<<x<<" ";
}

/*Madhav's PAPA: Solution*/
void sortColors(vector<int>& arr) {
        int p = 0, q = 0, r = arr.size()-1; int i=0;
        while(i<arr.size()){ // sort 1st 0's
            if(arr[i]==0)
                swap(arr[p++], arr[i]);                       
            i++;
        } // set all zero
        i = p;
        while(i<arr.size()){ // sort 1's later
            if(arr[i]==1)
                swap(arr[p++], arr[i]);
            i++;
        }

}

int main(){
    vector<int> arr = {0,0,2,1,1,1,1,2,0,2,0,1,0,2,0,2,0,0,2,2,0}; // 0 0 0 0 1 2 1 1M 2R
                                                
    sortArr(arr);
    return 0;
}