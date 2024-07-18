// program to find the nearest power of 2 of the given number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n; 
    int x = std::bit_width(n);
    cout << x-1 << endl;
    return 0;
}