#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	vector<int> dp(n + 1, -1);
	dp[n] = 0;


	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > 0) {
			int mn = INT_MAX;
			for (int j = i + 1; j <= min(arr[i] + i , n); j++)
			{
				if (dp[j] != -1)
					mn = min(mn, dp[j]);
			}
			if (mn != INT_MAX)
				dp[i] = mn + 1;
		}
	}

	if (dp[0] == -1)
		cout << "null" << endl;
	else
		cout << dp[0] << endl;

	return 0;
}