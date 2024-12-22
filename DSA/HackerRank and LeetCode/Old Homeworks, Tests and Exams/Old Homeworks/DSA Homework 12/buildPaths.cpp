#include <set>
#include <cmath>
#include <tuple>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Edge {
    long long c1, weight;
    int y, idx;
    
    Edge(int y, long long c1, long long weight, int idx)
        : c1(c1), weight(weight), y(y), idx(idx) {}
    
    Edge(long long c1, long long weight, int y, int idx)
        : c1(c1), weight(weight), y(y), idx(idx) {}
    
    bool operator>(const Edge& other) const {
        if(c1 == other.c1) {
            return weight <= other.weight;
        }
        return c1 > other.c1;
    }
};

unordered_map<int, vector<Edge>> graph; 
unordered_set<int> vertexes;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void add_edges(int vertex) {
    for (auto& edge : graph[vertex]) {
        if (vertexes.count(edge.y)) {
            continue;
        }
        pq.push(edge);
    }
}

void prim() {
    set<int> edges;
    int start_vertex = (graph.begin())->first;
    vertexes.insert(start_vertex);
    add_edges(start_vertex);
    while(vertexes.size() != graph.size() && pq.size()) {
        auto minEdge = pq.top();
        pq.pop();
        if (vertexes.count(minEdge.y) || edges.count(minEdge.idx)) {
            continue;
        }
        vertexes.insert(minEdge.y);
        add_edges(minEdge.y);
        edges.insert(minEdge.idx);
    }    
    for(auto id : edges) {
        cout << id << '\n';
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; 
        long long c1, c2;
        cin >> x >> y >> c1 >> c2;
        long long weight = c1 * c2;
        graph[x].emplace_back(y, c1, weight, i);
        graph[y].emplace_back(x, c1, weight, i);
    }
    prim();
    return 0;
}
