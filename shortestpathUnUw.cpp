#include<bits/stdc++.h>
using namespace std;

void ShortestPath(int v, int src, vector<int>graph[])
{
	vector<int>dist(v, INT_MAX);

	dist[src] = 0;

	queue<int> q;

	q.push(src);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto nbr : graph[node])
		{
			if (dist[nbr] == INT_MAX)
			{
				q.push(nbr);
				dist[nbr] = 1 + dist[node];
			}
		}
	}

	for (int i  = 0; i < v ; i++)
		cout  << dist[i] << ' ';

	cout << endl;
}

void dfs_helper(vector<int>graph[], vector<int>&visited, int src)
{

	for (auto nbr : graph[src])
	{

		if (visited[nbr] > 1 + visited[src]) {
			visited[nbr] = 1 + visited[src];
			dfs_helper(graph, visited, nbr);
		}

	}
}

void ShortestPathdfs(int v, int src, vector<int>graph[]) {
	vector<int> visited(v, INT_MAX);
	visited[src] = 0;
	dfs_helper(graph, visited, src);

	for (auto val : visited)
		cout << val << ' ';
	cout << endl;
}


int main() {
	int v, e;
	cin >> v >> e;

	vector<int> graph[v];
	int a, b;
	for (int i  = 0; i < e; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	ShortestPath(v, 0, graph);

	ShortestPathdfs(v, 0, graph);

	return 0;
}