#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> graph[int(1e6) + 1];
bool visited[int(1e6) + 1];

int count = 0;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    ::count = 1;
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int fv = q.front();
            q.pop();
            for(auto cv : graph[fv]) {
                if(!visited[cv]) {
                    visited[cv] = true;
                    q.push(cv);
                    ::count++;
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        bfs(i);
        if(::count % k == 0) {
            res++;
        }
        ::count = 0;
    }
    cout << res;
    return 0;
}
