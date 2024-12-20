#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> checked;

int counter = 0;

int dfs(int v) {
    int ace = 1;
    checked.insert(v);
    for(auto cv : graph[v]) {
        if(checked.find(cv) != checked.end()) {
            continue;
        }
        int ce = dfs(cv);     
        if(ce % 2 == 0) {
            counter++;
        } else {
            ace += ce;
        }
    }
    return ace;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    dfs((*graph.begin()).first);
    cout << counter;
    return 0;
}
