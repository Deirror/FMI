#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int dfs(int v, unordered_map<int, vector<int>>& graph, bool* visited, int t) {
    if(v == t) {
        return 1;
    }
    visited[v] = true;
    int count = 0;
    for(auto cv : graph[v]) {
        if(!visited[cv]) {
            count += dfs(cv, graph, visited, t);
        }
    }
    visited[v] = false;
    return count;
}

int counter(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for(size_t i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    bool visited[n + 1]{};
    return dfs(1, graph, visited, n);
}

vector<int> shortestReach(int n, vector<vector<int>>& edges, int s) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for(size_t i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(pq.size()) {
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(cost > dist[v]) {
            continue;
        }
        for(auto& cv : graph[v]) {
            int ch = cv.first;
            int chCost = cv.second;
            if(dist[ch] > dist[v] + chCost) {
                dist[ch] = dist[v] + chCost;
                pq.push({dist[ch], ch});
            }
        }
    }
    return dist;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }   
    vector<int> dist = shortestReach(v, edges, 1);
    if(dist[v] == INT_MAX) {
        cout << "-1 0";
        return 0;
    }
    int count = counter(v, edges);
    cout << dist[v] << ' ' << count;
    return 0;
}
