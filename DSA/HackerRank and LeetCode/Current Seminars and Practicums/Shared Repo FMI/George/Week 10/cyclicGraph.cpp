#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool dfs(int v, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, unordered_set<int>& toDelete) {
    if(visited.find(v) != visited.end() || toDelete.find(v) != toDelete.end()) {
        return false;
    }
    visited.insert(v);
    for(auto cv : graph[v]) {
        if(visited.find(cv) != visited.end() && toDelete.find(cv) != toDelete.end()) {
            continue;
        } else if(visited.find(cv) != visited.end() && toDelete.find(cv) == toDelete.end()) {
            return true;
        }
        if(dfs(cv, graph, visited, toDelete)) {
            return true;
        }
    }
    toDelete.insert(v);
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
     cin >> q;
    for(int i = 0; i < q; i++) {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_set<int>> graph;
        for(int j = 0; j < e; j++) {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].insert(y);
        }
        unordered_set<int> visited;
        unordered_set<int> toDelete;
        bool flag = false;
        auto it = graph.begin();
        while(it != graph.end()) {
            if(dfs((*it).first,graph, visited, toDelete)) {
                flag = true;
                break;
            }
            it++;
        }
        if(flag) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    return 0;
}
