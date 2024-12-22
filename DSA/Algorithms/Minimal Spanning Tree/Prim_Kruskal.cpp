#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

enum class Algorithm : bool {
	Prim,
	Kruskal
};

unordered_map<int, vector<pair<int, int>>> create_graph(vector<vector<int>>& edges) {
	unordered_map<int, vector<pair<int, int>>> graph;
	for (auto& edge : edges) {
		graph[edge[0]].push_back({ edge[1], edge[2] });
		graph[edge[1]].push_back({ edge[0], edge[2] });
	}
	return graph;
}

void add_edges(int vertex, unordered_set<int>& vertexes, unordered_map<int, vector<pair<int, int>>>& graph, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>& pq) {
	for (auto& edge : graph[vertex]) {
		if (vertexes.count(edge.first)) {
			continue;
		}
		pq.push({ edge.second, {edge.first, vertex} });
	}
}

unordered_map<int, vector<pair<int, int>>> prim(vector<vector<int>>& edges) {
	unordered_map<int, vector<pair<int, int>>> graph = create_graph(edges);
	unordered_map<int, vector<pair<int, int>>> mst;

	unordered_set<int> vertexes;
	int start_vertex = (*graph.begin()).first;
	vertexes.insert(start_vertex);

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	add_edges(start_vertex, vertexes, graph, pq);
	//assuming it is connected, otherwise inf cycle! 
	while (vertexes.size() != graph.size()) {
		auto minEdge = pq.top();
		pq.pop();
		int weight = minEdge.first;
		int child = minEdge.second.first;
		int parent = minEdge.second.second;
		if (vertexes.count(child)) {
			continue;
		}
		mst[parent].push_back({child, weight});
		mst[child].push_back({parent, weight});
		vertexes.insert(child);
		add_edges(child, vertexes, graph, pq);
	}
	return mst;
}

unordered_map<int, vector<pair<int, int>>> find_msp(Algorithm algorithm) {
	int m;
	cin >> m;
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({ x, y, w });
	}
	switch (algorithm) {
	case Algorithm::Prim: {
		return prim(edges);
	}
	case Algorithm::Kruskal: {

	}
	}
	return {};
}

int main() {
	auto mst = find_msp(Algorithm::Prim);
	for (auto& kvp : mst) {
		cout << kvp.first << ":\n";
		for (auto& edge : kvp.second) {
			cout << "  " << edge.first << ", " << edge.second << '\n';
		}
	}
	return 0;
}
