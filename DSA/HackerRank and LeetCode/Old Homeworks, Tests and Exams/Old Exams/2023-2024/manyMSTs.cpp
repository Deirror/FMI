#include <bits/stdc++.h>
using namespace std;

void addEdges(int vertex, unordered_map<int, vector<pair<int, int>>>& graph, unordered_set<int>& visited, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq) {
    for(auto& kvp : graph[vertex]) {
        if(!visited.count(kvp.first)) {
            pq.push({kvp.second, kvp.first});
        }
    }
}

size_t prim(int startVertex, unordered_map<int, vector<pair<int, int>>>& graph, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_set<int> visited;
    visited.insert(startVertex);
    addEdges(startVertex, graph, visited, pq);
    size_t res = 0;
    while(n != visited.size() && pq.size()) {
        auto minEdge = pq.top();
        pq.pop();
        if(visited.count(minEdge.second)) {
            continue;
        }
        visited.insert(minEdge.second);
        addEdges(minEdge.second, graph, visited, pq);
        res += minEdge.first;
    }
    return res;
}

int vertexCount(int vertex, unordered_map<int, vector<pair<int, int>>>& graph, unordered_set<int>& visited) {
    visited.insert(vertex);
    int count = 1;
    for(auto& neighbour : graph[vertex]) {
        if(!visited.count(neighbour.first)) {
            count += vertexCount(neighbour.first, graph, visited);
        }
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        unordered_map<int, vector<pair<int, int>>> graph;
        while(m--) {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].emplace_back(y, w);
            graph[y].emplace_back(x, w);
        }        
        unordered_set<int> visited;
        size_t sum = 0;
        for(int i = 0; i < n; i++) {
            if(!visited.count(i)) {
                int cv = vertexCount(i, graph, visited);
                if(cv % k == 0) {
                    sum += prim(i, graph, cv);
                }
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}
