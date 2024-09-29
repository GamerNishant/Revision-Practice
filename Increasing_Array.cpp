#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    long long sum = 0;
    int prev;
    for(int i = 0; i<n;i++)
    {
        int x;
        cin>>x;
        if(i == 0) prev = x;
        else{
            if(x < prev) sum += prev-x;
            else{
                prev = x;
            }
        }
    }
    cout << sum << endl;
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