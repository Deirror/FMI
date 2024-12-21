#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void dfs(int v, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
    visited.insert(v);
    for(auto cv : graph[v]) {
        if(!visited.count(cv)) {
            dfs(cv, graph, visited);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_set<int>> graph;
        for(int j = 0; j < v; j++) {
            graph[j];
        }
        for(int j = 0; j < e; j++ ){
            int x, y;
            cin >> x>>y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        unordered_set<int> visited;
        int count = 0;
        for(int j = 0; j < v; j++) {
            if(!visited.count(j)) {
                dfs(j, graph, visited);
                count++;
            }
        }
        cout << count << ' ';
    }
    return 0;
}
