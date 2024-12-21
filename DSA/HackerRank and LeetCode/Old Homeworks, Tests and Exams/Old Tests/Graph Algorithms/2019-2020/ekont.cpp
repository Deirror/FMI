#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef struct WeightedVertex {
    int data;
    int weight;
    
    bool operator>(const WeightedVertex& other) const {
        return weight > other.weight;
    }
} WV;

unordered_map<int, vector<WV>> graph;
vector<size_t> d(2*int(1e5) + 1, INT_MAX);

void fill(int sv, vector<size_t>& d) {
    d[sv] = 0;
    priority_queue<WV, vector<WV>, greater<WV>> pq;
    pq.push({sv, 0});
    while(pq.size()) {
        int vd = pq.top().data;
        int w = pq.top().weight;
        pq.pop();
        if(d[vd] > w) {
            continue;
        }
        for(auto& cv : graph[vd]) {
            if(d[cv.data] > w + cv.weight) {
                d[cv.data] = w + cv.weight;
                pq.push({cv.data, w + cv.weight});
            }
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int start;
    cin >> start;
      
    fill(start, d);
    
    for(int i = 1; i <= n; i++) {
        if(start == i) {
            continue;
        }
        if(d[i] != INT_MAX) {
            cout << d[i] << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    
    return 0;
}
