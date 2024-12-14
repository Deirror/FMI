#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

void bfs(int startVertex, bool* checked) {
    queue<int> q;
    q.push(startVertex);
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int v = q.front();
            checked[v] = true;
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
    int t;
    cin >> t;
    for(int j = 0; j < t; j++) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            graph[i] = vector<int>();
        }
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int count = 0;
        bool checked[int(1e5) + 1]{};
        while(graph.size()) {
            bfs((*graph.begin()).first, checked);
            count++; 
        }
        cout << count << ' ';
    }
    return 0;
}
