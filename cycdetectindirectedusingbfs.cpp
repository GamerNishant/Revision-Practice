#include<bits/stdc++.h>

using namespace std;

bool topoSort(int N, vector<int> adj[], vector<int> &topo)
{
	queue<int> q;
	vector<int> indegree(N, 0);
	for (int i = 0; i < N; i++)
	{
		for (auto it : adj[i])
		{
			indegree[it]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}



	while (!q.empty())
	{
		int node = q.front();

		q.pop();

		topo.push_back(node);

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	if (topo.size() == N)
		return true;

	return false;
}

int main() {
	int v;
	cin >> v;
	int e;
	cin >> e;
	vector<int> adj[v];
	int a, b;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);

	}

	for (int i = 0; i < v; i++)
	{
		cout << i << "->";
		for (auto val : adj[i])
			cout << val << ' ';

		cout << endl;
	}

	vector<int> ans;
	if (topoSort(v, adj, ans))
		cout << "NO";

	else
		cout << "YES" << endl;

	for (auto val : ans)
		cout << val << ' ';

	cout << endl;

	return 0;
}