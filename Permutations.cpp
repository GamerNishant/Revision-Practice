#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; 
    cin>>n;
    if(n == 1) {cout << 1 << endl; return ;}
    if(n == 4) {cout << 2 << 4 << 1 << 3 << endl; return;}
    if(n < 4) {cout << "NO SOLUTION" << endl;
    return ;}
    
    int even, odd;
    odd = (n%2) ? n : n-1;
    even = (n%2) ? n-1 : n;
    

    while(even > 0)
    {
        cout << even << ' ';
        even -= 2;
    }
    while(odd > 0)
    {
        cout << odd << ' ';
        odd -= 2;
    }

    return ;
}

int main(){
    int t = 1; 
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}