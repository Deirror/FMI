#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;
bool checked[int(1e6) + 1];
int component[int(1e6) + 1];

void bfs(int startVertex, int id) {
    queue<int> q;
    q.push(startVertex);
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int v = q.front();
            checked[v] = true;
            component[v] = id;
            for(auto cv : graph[v]) {
                if(!checked[cv]) {
                    checked[cv] = true;
                    q.push(cv);
                }
            }
            graph.erase(v);
            q.pop();
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int id = 1;
    while(graph.size()) {
        bfs((*graph.begin()).first, id++);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        cout << (component[s] == component[e]) << ' '; 
    }
    return 0;
}
