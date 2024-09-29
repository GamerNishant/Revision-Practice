#include<bits/stdc++.h>
using namespace std;



void solve(int a[], int n, int t, int idx, int sum, vector<int> ans)
{
    if(sum > t || idx == n) return;

    if(sum == t){
        for(auto v : ans) cout << v << ',';
        cout << endl;
        return;
    }

    for(int i = idx; i<n; i++)
    {
        if(i!=idx and a[i] == a[i-1]) continue;
        ans.push_back(a[i]);
        solve(a, n, t, i+1, sum+a[i], ans);
        ans.pop_back();
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
    sort(arr, arr + n);
    solve(arr, n, t, 0, 0, ans);
    return 0;
}