#include<bits/stdc++.h>

using namespace std;

class Graph {
	int v;
	unordered_map<int, list<int>> adjlist;
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

	bool dfs_helper(int node , vector<bool>& visited, int parent) {
		visited[node] = true;
		cout << node << ',';
		for (auto nbr : adjlist[node]) {
			if (!visited[nbr])
			{
				if (dfs_helper(nbr, visited, node)) return true;
			}
			else if (parent != nbr) return true;
		}

		return false;
	}

	bool dfs() {
		vector<bool> visited(v, false);
		return dfs_helper(0, visited, -1);
		cout << endl;
	}

	void findcycle() {
		if (dfs()) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;
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
	g.findcycle();
	return 0;
}