#include <iostream>
#include <queue>
#include <list>
#include <unordered_map> // unordered_map
#include <map> // unordered_map
using namespace std;

class Graph {
public:
	map<string, list<string> > adj;

	void addEdge(string u, string v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto neighbours : p.second) {
				cout << neighbours << " ";
			}
			cout << endl;
		}
	}

	void SSSP(string src, string des) {
		map<string, bool > visited;
		map<string, int > dist;
		map<string, string > parent;

		queue<string> q;
		q.push(src);
		parent[src] = src;
		dist[src] = 0;
		visited[src] = true;

		while (!q.empty()) {
			string d = q.front();

			q.pop();

			for (auto ch : adj[d]) {
				if (!visited[ch]) {
					visited[ch] = true;
					q.push(ch);
					dist[ch] = dist[d] + 1;
					parent[ch] = d;
				}
			}
		}

		cout << "Min Dist from " << src << " to " << des << " : " << dist[des] << endl;
		// Print the path from src to des
		while (des != parent[des]) {
			cout << des << " <-- ";
			des = parent[des];
		}
		cout << des << endl;
	}
};

int main() {

	Graph g;

	g.addEdge("1", "0");
	g.addEdge("4", "0");
	g.addEdge("1", "2");
	g.addEdge("4", "3");
	g.addEdge("4", "2");
	g.addEdge("3", "2");
	g.addEdge("3", "5");

	// g.print();
	g.SSSP("1", "5");




	return 0;
}
















