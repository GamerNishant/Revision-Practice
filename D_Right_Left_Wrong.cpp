#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>> arr[i];
    }
    string s; 
    cin>>s;

    int l, r;
    l = 0, r = n-1;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'L')
        {
            l = i;
            break;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        if(s[i] == 'R')
        {
            r = i;
            break;
        }
    }
    

    if(l>r) cout << 0 << endl;
    else{
        int ans = 0;
        for(int i=l; i<=r;i++) ans += arr[i];
        cout << ans << endl;
    }

    return;
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