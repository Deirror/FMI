#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

!!! written under 2 minutes and solved at the first try !!!

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> visited;

int dfs(int s) {
    visited.insert(s);
    int ace = 1;
    for(auto x : graph[s]) {
        if(!visited.count(x)) {
            ace += dfs(x);
        }
    }
    return ace;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int v, e, k;
    cin >> v >> e >> k;
    for(int i = 0; i < v; i++) graph[i];
    while(e--) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!visited.count(i)) {
            if(dfs(i) % k == 0) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
