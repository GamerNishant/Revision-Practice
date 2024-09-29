#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    int a[m+1] ={};
    for(int i=0;i<m+1; i++){
        cin>>a[i];
    }

    int ans = 0;
    int i=0;
    while(i<m){
        int x = __builtin_popcount((a[m]^a[i]));
        i++;
        if(x <= k) ans+=1;
    }
    cout << ans << endl;    
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