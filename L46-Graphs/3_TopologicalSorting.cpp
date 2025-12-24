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

	void tps_helper(string src, unordered_map<string, bool> &visited, stack<string> &ans) {

		visited[src] = true;

		for (auto ch : adj[src]) {
			if (!visited[ch]) {
				tps_helper(ch, visited, ans);
			}
		}
		// src node ko last mei shuru mei insert karte jaao
		ans.push_front(src);
	}

	void tps() {
		unordered_map<string, bool> visited;
		stack<string> ans;

		for (auto p : adj) {
			if (!visited[p.first]) {
				tps_helper(p.first, visited, ans);
			}
		}

		for (auto d : ans) {
			cout << d << " ";
		}
	}
};

int main() {

	Graph g;

	g.addEdge("english", "c++", false);
	g.addEdge("english", "maths", false);
	g.addEdge("hindi", "maths", false);
	g.addEdge("hindi", "java", false);
	g.addEdge("c++", "dsa", false);
	g.addEdge("maths", "dsa", false);
	g.addEdge("dsa", "web", false);
	g.addEdge("web", "python", false);
	g.addEdge("java", "android", false);
	g.addEdge("android", "springboot", false);
	g.addEdge("android", "python", false);

	g.tps();
	cout << endl;

	return 0;
}
















