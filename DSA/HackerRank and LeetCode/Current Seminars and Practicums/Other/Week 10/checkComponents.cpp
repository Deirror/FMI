#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> graph[int(1e6) + 1];
int component[int(1e6) + 1];
bool visited[int(1e6) + 1];

int componentId = 1;

void hookToComponent(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    component[v] = componentId;
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int f = q.front();
            for(auto cv : graph[f]) {
                if(!visited[cv]) {
                    visited[cv] = true;
                    component[cv] = componentId;
                    q.push(cv);
                }
            }
            q.pop();
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= v; i++) {
        if(!visited[i]) {
            hookToComponent(i);
            componentId++;
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (component[x] == component[y]) << ' ';
    }
    return 0;
}
