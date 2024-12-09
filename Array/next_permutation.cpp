#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// "4, 1, 2, 5, 3" => "4 , 1, 3, 2 5"
// 4,1,3,2,5,6
void nextperm(vector<int>& arr){
    int n = arr.size();
    int idx1=-1, idx2; // 2 3 1 > 3 2 1 > 3 1 2
    for(int i=n-1;i>0;i--){        
        if(arr[i-1]<arr[i]){
            idx1 = i-1;            
            break;
        }
    }    
    // 4,1,3,2,5,6
    if(idx1!=-1){
       for(int i=n-1;i>idx1;i--){
            if(arr[idx1]<arr[i]){
                idx2 = i;
                break;
            }
       }       
       
       swap(arr[idx1], arr[idx2]);        
    }       
    reverse(arr.begin()+idx1+1, arr.end());  
}

int main(){
    vector<int> arr{2,3,1}; // 4 1 3 2 6 5    //3 1 2
    
    nextperm(arr);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}