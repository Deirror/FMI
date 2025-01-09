#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool dfs(int v, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
    visited.insert(v);
    for(auto ng : graph[v]) {
        if(visited.count(ng)) {
            return true;
        }
        if(dfs(ng, graph, visited)) {
            return true;
        }
    }
    visited.erase(v);
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_set<int>> graph;
        for(int j = 0; j < e; j++) {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].insert(y);
        }
        unordered_set<int> visited;
        bool flag = false;
        for(int j = 0; j < v; j++) {
            if(!visited.count(j)) {
                if(dfs(j, graph, visited)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    return 0;
}
