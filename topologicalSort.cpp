#include<bits/stdc++.h>

using namespace std;

class Graph {
	int v;
	unordered_map<int, list<int>> adjlist;
	stack<int> st;
public:
	Graph(int v) {
		this->v = v;
	}

	void insert(int a, int b) {
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	void print() {
		for (int i = 0; i < v; i++) {
			cout << i << "->";
			for (auto val : adjlist[i]) {
				cout << val << ',';
			}
			cout << endl;
		}
	}

	void dfs_helper(int node , vector<bool>& visited) {
		visited[node] = true;
		cout << node << ',';
		for (auto nbr : adjlist[node]) {
			if (!visited[nbr])
			{
				dfs_helper(nbr, visited);
			}
		}
		st.push(node);
	}

	void dfs() {
		vector<bool> visited(v, false);
		dfs_helper(0, visited);
		cout << endl;
	}

	void bfs() {

		vector<bool> visited(v, false);
		vector<int> ans;
		cout << endl;
		queue<int> q;
		q.push(0);
		q.push(-1);
		visited[0] = true;
		while (!q.empty()) {
			auto node = q.front();
			if (node == -1)
			{
				cout << endl;
				q.pop();
				if (!q.empty())
					q.push(-1);
			}
			else {
				ans.push_back(node);
				cout << node << ',';
				q.pop();
				for (auto nbr : adjlist[node])
					if (!visited[nbr])
					{
						visited[nbr] = true;
						q.push(nbr);
					}
			}
		}
		cout << endl;

		for (auto val : ans) {
			cout << val << ' ';
		}
		cout << endl;
	}

	void topologicalSort() {
		dfs();
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
			cout << ' ';
		}
		bfs();
	}
};

int main() {
	int e, v;
	cin >> e >> v;

	Graph g(v);
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		g.insert(a, b);
	}
	g.print();
	g.topologicalSort();
	return 0;
}