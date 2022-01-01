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

	void sssp(int src)
	{
		vector<int> dist(v, INT_MAX);
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while (!q.empty()) {
			auto node = q.front();
			q.pop();

			for (auto nbr : adjlist[node]) {
				if (dist[nbr] == INT_MAX) {
					dist[nbr] = dist[node] + 1;
					q.push(nbr);
				}
			}
		}

		for (int i = 0; i < v; i++) {
			cout << dist[i] << ',';
		}
		cout << endl;
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
	g.sssp(0);
	return 0;
}