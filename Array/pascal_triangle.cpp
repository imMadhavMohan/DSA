vector<vector<int>> pascalTriangle(int n) {
    // Write your code here.
    vector<vector<int>> arr(n);
    int i=0,j=0;
    while(i<n){
       arr[i].resize(i+1);       
       arr[i][j] = 1;
       arr[i][0] = 1;
       i++; j = i;
    }
    
    for(int i=2; i<n ;i++){
        j = 1;
        while(j<i){
        arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        j++;     
        }   
    }
    return arr;
}