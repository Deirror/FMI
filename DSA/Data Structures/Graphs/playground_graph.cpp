#include <stack>
#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;

enum class Algorithm : char {
	Dijkstra,
	BellmanFord,
	TopoSortGAD
};

unordered_map<int, vector<pair<int, int>>> create_graph(vector<vector<int>>& edges, bool isDirected = false) {
	unordered_map<int, vector<pair<int, int>>> graph;
	for (auto& edge : edges) {
		graph[edge[0]].push_back({edge[1], edge[2]});
		if (!isDirected) {
			graph[edge[1]].push_back({ edge[0], edge[2] });
		}
	}
	return graph;
}

vector<int> max_dijkstra(int n, vector<vector<int>>& edges, int s, bool isDirected) {
	unordered_map<int, vector<pair<int, int>>> graph = create_graph(edges, isDirected);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	vector<int> dist(n + 1, 0);
	dist[s] = 0;
	while (pq.size()) {
		int v = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost < dist[v]) {
			continue;
		}
		for (auto& kvp : graph[v]) {
			int cv = kvp.first;
			int cvCost = kvp.second;
			if (dist[cv] < dist[v] + cvCost) {
				dist[cv] = dist[v] + cvCost;
				pq.push({ dist[cv], cv });
			}
		}
	}
	return dist;
}

vector<int> dijkstra(int n, vector<vector<int>>& edges, int s, bool isDirected) {
	unordered_map<int, vector<pair<int, int>>> graph = create_graph(edges, isDirected);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	vector<int> dist(n + 1, INT_MAX);
	dist[s] = 0;
	while (pq.size()) {
		int v = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dist[v]) {
			continue;
		}
		for (auto& kvp : graph[v]) {
			int cv = kvp.first;
			int cvCost = kvp.second;
			if (dist[cv] > dist[v] + cvCost) {
				dist[cv] = dist[v] + cvCost;
				pq.push({dist[cv], cv});
			}
		}
	}
	return dist;
}

vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
	vector<int> dist(n + 1, INT_MAX);
	dist[s] = 0;
	size_t e = edges.size();
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < e; j++) {
			auto& edge = edges[j];
			dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
		}
	}
	return dist;
}


void dfs(unordered_map<int, vector<pair<int, int>>>& graph, int v, bool* visited, stack<int>& topoOrder) {
	visited[v] = true;
	for (auto& edge : graph[v]) {
		if (!visited[edge.first]) {
			dfs(graph, edge.first, visited, topoOrder);
		}
	}
	topoOrder.push(v);
}

stack<int> topoSort(int n, unordered_map<int, vector<pair<int, int>>>& graph) {
	stack<int> topoOrder = stack<int>();
	bool* visited = new bool[n + 1] {};
	for (int i = 0; i < n + 1; i++) {
		if (!visited[i]) {
			dfs(graph, i, visited, topoOrder);
		}
	}
	return topoOrder;
}

vector<int> shortestPathGAD(int s, int n, vector<vector<int>>& edges) {
	unordered_map<int, vector<pair<int, int>>> graph = create_graph(edges, true);
	stack<int> topoOrder = topoSort(n, graph);
	vector<int> dist(n + 1, INT_MAX);
	dist[s] = 0;
	while (!topoOrder.empty()) {
		int v = topoOrder.top();
		topoOrder.pop();
		for (auto& kvp : graph[v]) {
			int cv = kvp.first;
			int cvCost = kvp.second;
			if (dist[cv] > dist[v] + cvCost) {
				dist[cv] = dist[v] + cvCost;
			}
		}
	}
	return dist;
}

int findShortestPathInit(Algorithm algorithm, bool findMinPath = true) {
	int n, m, s, e;
	bool isDirected = true;;
	cin >> n >> m >> s >> e;
	if (algorithm == Algorithm::Dijkstra) {
		cin >> isDirected;
	}
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({ x, y, w });
	}
	switch (algorithm) {
	case Algorithm::Dijkstra: {
		return findMinPath ? dijkstra(n, edges, s, isDirected)[e] : max_dijkstra(n, edges, s, isDirected)[e];
	}
	case Algorithm::BellmanFord: {
		return bellman_ford(n, edges, s)[e];
	} 
	case Algorithm::TopoSortGAD: {
		return shortestPathGAD(s, n, edges)[e];
	}
	}
	return -1;
}

int main() {
	cout << findShortestPathInit(Algorithm::Dijkstra);
	return 0;
}
