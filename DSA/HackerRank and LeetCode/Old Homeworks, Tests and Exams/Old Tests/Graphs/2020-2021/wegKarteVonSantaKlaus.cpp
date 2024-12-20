#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> checked;

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int x = q.front();
            checked.insert(x);
            for(auto cv : graph[x]) {
                if(checked.find(cv) == checked.end()) {
                    checked.insert(cv);
                    q.push(cv);
                }
            }
            graph.erase(x);
            q.pop();
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x != y) {
            graph[x].insert(y);
            graph[y].insert(x);
        }
    }
    int count = 0;
    while(graph.size()) {
        bfs((*graph.begin()).first);
        count++;
    }
    cout << count;
    return 0;
}
