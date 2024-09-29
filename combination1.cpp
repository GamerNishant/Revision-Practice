#include<bits/stdc++.h>
using namespace std;



void solve(int a[], int n, int t, int i, int sum, vector<int> ans)
{
    if(sum > t || i == n) return;

    if(sum == t){
        for(auto v : ans) cout << v << ',';
        cout << endl;
        return;
    }

    if(sum+a[i] <= t)
    {
        ans.push_back(a[i]);
        solve(a, n, t, i, sum+a[i], ans);
        ans.pop_back();
        solve(a, n, t, i+1, sum, ans);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    int t;
    cin>>t;
    vector<int> ans;
    solve(arr, n, t, 0, 0, ans);
    return 0;
}