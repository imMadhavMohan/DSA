#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// int kandaneAlgo(vector<int> arr){
//     int n = arr.size();
//     int sum = 0;
//     int max = 0; int idx;

//     for(int i=0; i<=n-2; i++){  // {2, 3, -8, 10, -1, 2, 3}
//         sum = arr[i];                // {2, 3, -8, 10, -1, 2, 3}
//         for(int j=i+1; j<n;j++){
//             sum+=arr[j];
//         }
//         if(sum>max){
//             max = sum;
//             sum = 0;
//         }            
//     }

//     return max;
// }

int kandaneAlgo(vector<int> arr){ // if any sub array sum is < 0 , set sum = 0 
    int n = arr.size(); int sum = 0, max=INT_MIN, idx1=-1,idx2=-1;
    bool allnegative = true; // all -ve num check

    for(auto i = arr.begin();i<arr.end();i++)
        if(*i >= 0){
            allnegative = false; // 0 -1 -2
            break;}
    
    if(!allnegative){                
        for(int i=0;i<n;i++){ // {7,1,3,-8,16}{2, 3, -8, 7, -1, 2, 3} // -2, -4, -1, 2, -4, 1 // -2, -4, 4, 3,-1
            sum+=arr[i];
            if(sum>=0){
                if(sum>max){
                    max = sum;
                    idx2 = i; 
                    if(idx1==-1) 
                        idx1 = i;                        
                    }  
            }
            else{   
                    sum = 0;
                    if(sum+arr[i+1]>max) 
                        idx1 = i+1;
                }                                                 
        }
    }else {
        for(int i=0;i<n;i++){ // {-3, -1, -2, 0,||-1, -2, -3} 
            if(arr[i]>max){
                sum = arr[i];
                max = sum;
                idx1 = idx2 = i;
                // cout<<idx1<<" "<<idx2<<endl;
            }else {
                sum = 0;
            }             
        }                                     
    }                                         
    cout<<idx1<<" "<<idx2<<endl;
    return max;
}


int main(){
    vector<int> arr = {7,1,3,-8, 16}; // {2, 3, -1, 7}; //{2, 3, -8, 7, -1, 2, 3}; {2, 3, -1, 7}; 
    cout<<endl<<kandaneAlgo(arr);
    return 0;
}