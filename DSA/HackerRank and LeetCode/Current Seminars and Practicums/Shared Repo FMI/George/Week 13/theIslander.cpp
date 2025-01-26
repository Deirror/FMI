#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

void dfs(int s) {
    visited.insert(s);
    for(auto ng : graph[s]) {
        if(!visited.count(ng)) {
            dfs(ng);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        while(e--) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs((*(graph.begin())).first);
        bool flag = true;
        if(visited.size() == v)  { // graph is connected
            int count = 0;
            for(auto& kvp : graph) {
                if(kvp.second.size() % 2 == 0) {
                    count++;
                }
            }
            if(count == v) {
                cout << "ecycle\n";
                 flag = false;
            } else if(count == v - 2) {
                cout << "epath\n";
                flag = false;
            }
        }
        if(flag) {
            cout << "none\n";
        }
        visited.clear();
        graph.clear();
    }
    return 0;
}
