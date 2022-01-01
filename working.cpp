#include <bits/stdc++.h>

using namespace std;


int collectGold(int i, int j, int n, int m, vector<vector<int>>& arr, vector<vector<int>> &dp) {

    //write your code here
   if(i == -1 or j == -1)
    return 0;
   if(i == n or j == m)
   {
     return 0;
   }

   if(dp[i][j] != -1)
   return dp[i][j];

  return dp[i][j] = arr[i][j] + max({collectGold(i+1, j+1, n, m , arr, dp), collectGold(i-1, j+1, n, m , arr, dp), collectGold(i, j+1, n, m , arr, dp)});

}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, -1));
   int mx = INT_MIN;
   for(int i = 0; i< n; i++)
   {
      mx = max(mx,collectGold(i, 0, n, m, arr, dp));
   }

   cout<<mx <<endl;

}