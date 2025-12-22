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

	void bfs(string src) {
		map<string, bool > visited;

		queue<string> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			string d = q.front();
			cout << d << " ";

			q.pop();

			for (auto ch : adj[d]) {
				if (!visited[ch]) {
					visited[ch] = true;
					q.push(ch);
				}
			}
		}
		cout << endl;
	}
};

int main() {

	Graph g;

	g.addEdge("A", "B");
	g.addEdge("D", "B");
	g.addEdge("D", "C");
	g.addEdge("A", "C");

	// g.print();

	g.bfs("A");


	return 0;
}
















