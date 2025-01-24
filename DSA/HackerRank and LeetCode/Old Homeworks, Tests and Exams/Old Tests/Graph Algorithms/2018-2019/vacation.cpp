#include <cmath>
#include <climits>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Edge {
    int x, y, w;
    
    Edge(int x, int y, int w) : x(x), y(y), w(w) {}
    
    bool operator<(const Edge& other) const {
        return w > other.w;
    } 
};

unordered_map<int, vector<Edge>> graph;

vector<size_t> dijkstra(int n, int s) {
    vector<size_t> dist(n + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<Edge> pq;
    pq.push({s, s, 0});
    while(pq.size()) {
        auto edge = pq.top();
        pq.pop();
        if(edge.w > dist[edge.y]) {
            continue;
        }
        for(auto& ng : graph[edge.y]) {
            if(dist[ng.y] > dist[edge.y] + ng.w) {
                dist[ng.y] = dist[edge.y] + ng.w;
                pq.push({edge.y, ng.y, dist[ng.y]});
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
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].emplace_back(x, y, w);
        graph[y].emplace_back(y, x, w);
    }
    int k;
    cin >> k;
    vector<size_t> dist = dijkstra(n, k);
    for(int i = 1; i <= n; i++) {
        if(i == k) {
            continue;
        }
        int d = dist[i];
        if(d == INT_MAX) d = -1;
        cout << d << ' ';
    }
    return 0;
}
