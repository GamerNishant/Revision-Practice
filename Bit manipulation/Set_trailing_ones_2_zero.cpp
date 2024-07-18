// program to clear all trailing 1's  <----end

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    cout << (n&(n+1)) << endl;
    return 0;
}