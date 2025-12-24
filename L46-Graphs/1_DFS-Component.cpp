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

	void dfsHelper(string src, unordered_map<string, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (auto ch : adj[src]) {
			if (!visited[ch]) {
				dfsHelper(ch, visited);
			}
		}
	}

	void DFS() {
		unordered_map<string, bool> visited;
		int components = 0;

		for (auto p : adj) {
			if (!visited[p.first]) {
				dfsHelper(p.first, visited);
				components++;
			}
		}


		cout << "\nComponents: " << components << endl;
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
	g.addEdge("6", "7");

	g.DFS();


	return 0;
}
















