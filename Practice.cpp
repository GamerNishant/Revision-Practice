#include<bits/stdc++.h>

using namespace std;

int ans = 0;
void dfs(vector<vector<int>> graph, int src , int C, vector<int> arr, vector<bool> &visited)
{
	visited[src] = true;
	if (C < 0)
		return;
	if ( graph[src].size() == 1)
	{
		ans++;
		return;
	}

	for (auto nbr : graph[src])
	{
		if (!visited[nbr])
		{
			if (arr[nbr] == 1)
			{
				dfs(graph, nbr, C - 1, arr, visited);
			}
			else
				dfs(graph, nbr, C, arr, visited);
		}
	}
	visited[src] = false;
}

solve(vector<int> &A, vector<vector<int> > &B, int C) {
	vector<vector<int>> graph(A.size());

	for (auto val : B) {
		graph[val[0] - 1].push_back(val[1] - 1);
		graph[val[1] - 1].push_back(val[0] - 1);
	}

	// for (int i = 0; i < A.size(); i++)
	// {
	// 	cout << i << "->";
	// 	for (auto val : graph[i])
	// 		cout << val << ',';
	// 	cout << endl;

	// }
	int src = 0;
	vector<bool> visited(A.size(), false);
	// for (auto val : visited) cout << val << ' ';
	// cout << endl;
	dfs(graph, src, C, A, visited);
	return ans;
}

int main() {
	int v;
	int e;
	cin >> v >> e;
	vector<int> arr(v);
	vector<vector<int>> edge(e, vector<int>(2));
	int c;

	for (int i = 0; i < v; i++)
	{
		cin >> arr[i];
	}

	// for (auto val : arr) cout << val << ' ';
	// cout << endl;

	int a, b;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		edge[i][0] = a;
		edge[i][1] = b;
	}

	// for (auto val : edge)
	// {
	// 	cout << val[0] << ' ' << val[1] << endl;
	// }

	cin >> c;
	// cout << c << endl;

	cout << solve(arr, edge, c);

	return 0;
}
