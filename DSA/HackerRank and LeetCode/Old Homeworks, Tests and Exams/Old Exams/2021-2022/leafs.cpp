#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
bool visited[2 * int(1e5) + 1];

size_t sum[2 * int(1e5) + 1];

void dfs(int v) {
    visited[v] = true;
    for(auto cv : graph[v]) {
        if(!visited[cv]) {
            dfs(cv);
        }
        sum[v] += cv + sum[cv];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, t;
    cin >> m >> t;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
    } 
    for(int i = 0; i < t; i++) {
        int q;
        cin >> q;
        if(!visited[q]) {
            dfs(q);
        }
        cout << sum[q] << '\n';
    }
    return 0;
}
