#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int component[int(1e6) + 1];
vector<int> graph[int(1e6) + 1];
bool visited[int(1e6) + 1];

void dfs(int i, int componentIndex) {
    if(visited[i]) {
        return;
    }  
    visited[i] = true;
    component[i] = componentIndex;
    for(auto child : graph[i]) {
        dfs(child, componentIndex);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int componentID = 1;
    for(int i = 0; i < n; i++) {
        dfs(i, componentID++);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        cout << (component[x] == component[y]) << ' ';
    }
    return 0;
}
