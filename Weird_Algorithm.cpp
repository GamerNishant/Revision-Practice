#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n; 
    cin>>n;

    while(n > 1)
    {
        cout << n << " ";

        if(n%2)
        {
            n = n*3 + 1;
        }else{
            n = n/2;
        }
    }
    cout << n << endl;
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