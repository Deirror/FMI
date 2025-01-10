#include <bits/stdc++.h>

using namespace std;

//1
void addEdges(int vertex, unordered_map<int, vector<pair<int, int>>>& graph, unordered_set<int>& visited, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq) {
    for(auto& kvp : graph[vertex]) {
        if(!visited.count(kvp.first)) {
            pq.push({kvp.second, kvp.first});
        }
    }
}

int prims(int n, vector<vector<int>> edges, int start) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for(auto& edge : edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
    }
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     long long sum = 0;
    int startVertex = (*graph.begin()).first;
    unordered_set<int> visited;
    visited.insert(startVertex);
    addEdges(startVertex, graph, visited, pq);
    while(n != visited.size() && pq.size()) {
        auto pr = pq.top();
        pq.pop();
        if(visited.count(pr.second)) {
            continue;
        }
        visited.insert(pr.second);
        sum += pr.first;
        addEdges(pr.second, graph, visited, pq);
    }
    return sum;
}

//2
struct Edge {
    int from, to, weight;
    
    Edge(int from, int to, int weight)
    : from(from), to(to), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return this->weight > other.weight;
    }
};

int prims(int n, vector<vector<int>> edges, int start) {
    unordered_map<int, vector<Edge>> graph;
    for(auto& edge : edges) {
        graph[edge[0]].emplace_back(edge[0],edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[1],edge[0], edge[2]);
    }
    unordered_set<int> visited;
    priority_queue<Edge> pq;
    pq.push({start, start, 0});
    int sum = 0;
    while(n != visited.size() && pq.size()) {
        auto edge = pq.top();
        pq.pop();
        if(visited.count(edge.to)) {
            continue;
        }
        visited.insert(edge.to);
        sum += edge.weight;
        for(auto& adj : graph[edge.to]) {
            if(!visited.count(adj.to)) {
                pq.push(adj);
            }
        }
    }
    return sum;
}
