// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void funstr(string str, int n){
    if(n==str.size()-1) // edge
        cout<<str<<endl;
    for(int i=n;i<str.size();i++){ // backtracing
        swap(str[i],str[n]);
        funstr(str, n+1);
        swap(str[i],str[n]);
    }
}

int main() {
    string str = "Madhav";
    funstr(str, 0);
    return 0;
}