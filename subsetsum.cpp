#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve(int a[], int n, int idx, int sum)
{
    if(idx == n) {
        cout << sum << endl;
        ans.push_back(sum);
        return;
    }

    solve(a, n, idx+1, sum + a[idx]);
    solve(a, n, idx+1, sum);
    return;
}

int main(){
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    solve(a, n, 0, 0);
    sort(ans.begin(), ans.end());
    for(auto v : ans) cout << v << ", ";
    cout << endl;
    return 0;
}