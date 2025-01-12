#include <cmath>
#include <climits>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Edge {
    int from, to, weight;
    
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

vector<int> dijkstra(int n, int s, unordered_map<int, vector<Edge>>& graph) {
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<Edge> pq;
    pq.push({s, s, 0});
    while(pq.size()) {
        auto edge = pq.top();
        pq.pop();
        if(dist[edge.to] < edge.weight) {
            continue;
        }
        for(auto& ng : graph[edge.to]) {
            if(dist[ng.to] > dist[edge.to] + ng.weight) {
                dist[ng.to] = dist[edge.to] + ng.weight;
                pq.push(ng);
            }
        }
    }
    return dist;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Edge>> graph;
    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].emplace_back(x,y,w);
        graph[y].emplace_back(y,x,w);
    }
    int s;
    cin >> s;
    vector<int> dist = dijkstra(n, s, graph);
    for(int i = 1; i <= n; i++ ){
        if(i == s) continue;
        if(dist[i] == INT_MAX) {
            cout << -1 << ' ';
        } else {
            cout << dist[i] << ' ';
        }
    }
    return 0;
}
