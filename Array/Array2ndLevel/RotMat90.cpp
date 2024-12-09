#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

/*
 1(00)   2(01)   3(02)    1 4 7        7 4 1     1(00) 4(01) 7(02) 10(03)
 4(10)   5(11)   6(12) => 2 5 8  =>    8 5 2  => 2     5     8     11
 7(20)   8(21)   9(22)    3 6 9        9 6 3     3     6     9     12


4 1 2
7 5 3
8 9 6
Intutuon: observe carefully 1st transpose & 2nd reverse each row
*/

// Brute force solution sqr matrix // pattern row = j & colm = 
void rotateMat(vector<vector<int>>& arr){
    vector<vector<int>> mat(arr.size(), vector<int>(arr.size()));
    for(int i=0; i<arr.size();i++){
        for(int j=0; j<arr.size();j++){
            mat[j][(arr[0].size()-1)-i] = arr[i][j];
        }
    }    
}

void printMat(vector<vector<int> > &arr){
     for(int i = 0;i<arr.size();i++){
        for(auto j = arr[i].begin();j<arr[i].end();j++) //
            cout<<*j<<" ";
        cout<<endl;
    }
}

vector<vector<int> > transePoseSqrMatrix(vector<vector<int> > &mat){
    int n = mat.size();
    cout<<n;
    
    int i = 0, j = 0;
    for( i = 0; i < n; i++){
        j = i+1; // swap only if i<j as swap(a[n][n], a[n][n]) is useless
        while(j < mat[i].size()){
            swap(mat[j][i], mat[i][j]);                        
            j++;
        }  
        // j=i+1; // swap only if i<j as swap(a[n][n], a[n][n]) is useless     
    }    
    for(int i=0;i<n;i++)
        reverse(mat[i].begin(), mat[i].end());
    printMat(mat); 
    return mat; 
}

vector<vector<int> > transePoseNonSqrMatrix(vector<vector<int> > &mat){
    int col = mat[0].size(); // 3
    int row = mat.size(); // 4
    vector<vector<int>> transePoseMat(col, vector<int>(row)); // pass rows = col as transpose cols = vector<int>(row) 

    for(int i = 0; i < row ; i++){ // col 4
        for(int j = 0; j < col ; j++){ // row 3
           transePoseMat[j][i]  = mat[i][j]; // 4x3 to 3x4 after transPose
        }
    }
    for(int i=0;i<col;i++)
        reverse(transePoseMat[i].begin(), transePoseMat[i].end());
    printMat(transePoseMat);     
    return transePoseMat;   
}

int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    if(arr.size()==arr[0].size())
        arr = transePoseSqrMatrix(arr);
    else 
        arr = transePoseNonSqrMatrix(arr);
   
    // rotateBy90(arr);
    return 0;
}




