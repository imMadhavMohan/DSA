#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// int maxProfit(vector<int>& arr){
//     int n = arr.size();
//     int max = -1;

//     for(int i=0;i<n;i++){        
//         for(int j = i+1;j<n;j++){
//            if(arr[j]-arr[i]>max){
//                 max = arr[j]-arr[i];
//            }   
//         }
//     }
//     if(max<0)
//         return 0;
//     return max;
// }

int maxProfit(vector<int>& arr){
    int n = arr.size();
    int max = INT_MIN, min = arr[0];

    for(int i=1;i<n;i++){        
        if(arr[i]>min){
            if(arr[i]-min>max)
                max = arr[i] - min; 
        }else min = arr[i];
    }
    if(max<0)
        return 0;
    return max;
}


int main(){
    vector<int> v = {7,2,5,1,3,6,4}; // {7,6,4,3,1}; {7, 2, 1, 4}
    cout<<maxProfit(v);
    return 0;
}