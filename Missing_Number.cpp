#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; 
    cin>>n; 
    long long sum = 0;
    long long k = n;
    while(n-1 > 0)
    {
        int x;
        cin>>x;
        sum+=x;
        n--;
    }
    // cout << sum << endl;
    cout << ((k * (k+1) * 1LL)/2*1LL) - sum << endl;
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