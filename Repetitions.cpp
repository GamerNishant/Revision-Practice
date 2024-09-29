#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    char ch = s[0];
    long long ans = 0;
    long long val = 1;
    for(int i=1;i<s.length();i++)
    {
        if(ch == s[i]) val++;
        else
        {
            ch = s[i];
            ans = max(ans, val);
            val = 1;
        }
    }
    cout << max(ans, val)<< '\n';
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