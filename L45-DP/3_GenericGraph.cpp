#include <iostream>
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
};

int main() {

	Graph g;

	g.addEdge("A", "B");
	g.addEdge("D", "B");
	g.addEdge("D", "C");
	g.addEdge("A", "C");

	g.print();


	return 0;
}
















