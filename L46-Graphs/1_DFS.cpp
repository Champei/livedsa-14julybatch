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

	void DFS(string src) {
		unordered_map<string, bool> visited;
		dfsHelper("1", visited);
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

	/*
	// This is a tedious way of doing this passing visited hashmap manually
	unordered_map<string, bool> visited;
	g.DFS("1", visited);
	*/

	g.DFS("1");


	return 0;
}
















