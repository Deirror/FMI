#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> visited;
int components[int(1e6) + 1];

int id = 1;

void dfs(int v) {
    components[v] = id;
    visited.insert(v);
    for(auto cv : graph[v]) {
        if(!visited.count(cv)) {
            dfs(cv);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v, e;
    cin >> v >> e;
    for(int i = 0 ; i< e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    for(int i = 1; i <= v; i++ ){
        if(visited.count(i)) {
            continue;
        }
        dfs(i);
        id++;
    }
    int p;
    cin >> p;
    for(int i = 0 ; i < p; i++) {
        int x, y;
        cin >> x >> y;
        cout << (components[x] == components[y]) << ' ';
    }
    return 0;
}
