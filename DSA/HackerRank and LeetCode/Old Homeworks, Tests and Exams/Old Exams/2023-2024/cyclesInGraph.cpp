#include <bits/stdc++.h>
using namespace std;

bool flag = false;

void dfs(int vertex, int parent, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
    visited.insert(vertex);
    for(auto neighbour : graph[vertex]) {
        if(neighbour == vertex) continue;
        if(visited.count(neighbour) && neighbour != parent) {
            ::flag = true;
        }
        if(!visited.count(neighbour)) {
            dfs(neighbour, vertex, graph, visited);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_set<int>> graph;
        while(e--) {
            int x, y;
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i < v; i++) {
            if(!visited.count(i)) {
                dfs(i, -1, graph, visited);
                if(::flag) {
                    count++;
                    ::flag = false;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
