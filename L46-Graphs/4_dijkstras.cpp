#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <unordered_map> // unordered_map
#include <map> // unordered_map
using namespace std;

class Graph {
public:
	map<string, list< pair<string, int> > > adj;

	void addEdge(string u, string v, int d, bool bidir = true) {
		adj[u].push_back({v, d});
		if (bidir) {
			adj[v].push_back({u, d});
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto chp : p.second) {
				cout << "(" << chp.first << ", " << chp.second << ") ";
			}
			cout << endl;
		}
	}

	void dijkstras(string src, string des) {
		set< pair<int, string> > s;
		unordered_map<string, string> parent;
		unordered_map<string, int> dist;

		for (auto p : adj) {
			dist[p.first] = INT_MAX;
		}

		parent[src] = src;
		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			auto p = *(s.begin());
			s.erase(s.begin());

			int cd = p.first;
			string x = p.second;

			for (auto chp : adj[x]) {
				string neigh = chp.first;
				int ed = chp.second;

				if (dist[neigh] > cd + ed) {
					auto f = s.find({dist[neigh], neigh});
					if (f != s.end()) {
						s.erase(f);
					}

					parent[neigh] = x;
					dist[neigh] = cd + ed;
					s.insert({dist[neigh], neigh});
				}
			}
		}
		cout << "Distance from " << src << " to " << des << " : " << dist[des] << endl;
		cout << "Path from " << src << " to " << des << " : ";
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;


	}
};

int main() {

	Graph g;
	g.addEdge("A", "B", 1);
	g.addEdge("D", "B", 2);
	g.addEdge("A", "D", 8);
	g.addEdge("C", "D", 3);
	g.addEdge("C", "A", 10);

	g.dijkstras("A", "C");

	return 0;
}
















