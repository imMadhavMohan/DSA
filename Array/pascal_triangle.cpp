/*
1(0,0)
1(1,0) 1(1,1)
1(2,0) 2(2,1) 1(2,2)
1(3,0) 3(3,1) 3(3,2) 1(3,3)
1(4,0) 4(4,1) 6(4,2) 4(4,3) 1(4,4)

00
10 11
20 21 22
30 31 32 33
40 41 42 43 44

arr[2][1] = arr[1][0] + arr[1][1]

so (4,2)th element of pascal triangle nCr = n! / (r! * (n-r)!) = 4x3x2/2x2 // n = n-1 & r = r-1
                                      nCr = nCn-r 
                                      nCr = n! 
Binomial cofficients:
(a+b)^n = nC0*a^n * b^0 + nC1*a^n-1 * b^1 + . . . + nCn*a^n-n * b^n

Optimisation: 10C3 = 10x9x8x7! / (3x2x1) (7!) = [for(i=n;i>(n-r);i--) / for(i=r;i>0;i--)]
int res = 1;
int nCr(int n, int r){ // n=10; r=3
    for(int i=0;i<r;i++){
        res *= (n-i);
        res /= (i+1);        
    }
}

int res = nCr(n,r)/fun1(r); // nCr

*/

// print nth row of pascal Triangle , idea nth row has n colm

int factorial(int n){
    if(r==1 or r==0)
        return 1;
    return n*factorial(n-1);
}

int combination(int n,int r){
    int val = factorial(n)/factorial(r)*factorial(n-1);
    return val;
}

vector<vector<int>> pascalTriangle(int n) {
    for(int i=0;i<n;i++){
        cout<<combination(n-1,n-1-i)<<" ";
    }
    cout<<endl;
}



vector<vector<int>> pascalTriangle(int n) { // print pascal trianle
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

