#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int k = 0;
    while(n >= (1<< k)){
        k++;
    }
    cout  << (1<<(k-1)) - 1 << endl;
}

int main(){
    int t = 1; 
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}