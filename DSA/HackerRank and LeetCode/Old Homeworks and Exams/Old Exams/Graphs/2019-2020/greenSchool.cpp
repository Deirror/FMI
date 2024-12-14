#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> graph[int(1e5) + 1];
bool checked[int(1e5) + 1];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    q.push(n);
    int level = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(q.size() && level < k) {
        int s = q.size();
        level++;
        for(int i = 0; i < s; i++) {
            int vertex = q.front();
            checked[vertex] = true;
            for(auto connectedVertex : graph[vertex]) {
                if(!checked[connectedVertex]) {
                    checked[connectedVertex] = true;
                    q.push(connectedVertex);
                }
            }
            if(level == k) {
                pq.push(vertex);
            }
            q.pop();
        }
    }
    if(pq.size()) {
        int s = pq.size();
        for(int i = 0; i < s; i++) {
            cout << pq.top() << ' ';
            pq.pop();
        }
    } else {
        cout << -1;
    }
    return 0;
}
