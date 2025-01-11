#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
    1.PRIM ALGORITHM
*/

struct Path {
    int idx;
    int from, to;
    long long eff, prize;
    
    Path(int idx, int from, int to, long long c1, long long c2) : idx(idx), from(from), to(to), eff(c1) {
        prize = c2 * c1;
    }
    
    bool operator<(const Path& other) const {
        if(eff > other.eff) {
            return true;
        } else if(eff == other.eff) {
           return prize < other.prize;
        }
        return false;
    }
};

unordered_map<int, vector<Path>> graph;

vector<Path> prim() {
    int n = graph.size();
    
    vector<Path> mst;
    
    priority_queue<Path> pq;
    pq.push({0, 1, 1, 0, 0});
    
    unordered_set<int> visited;
    while(pq.size() && visited.size() != n) {
        auto path = pq.top();
        pq.pop();
        if(visited.count(path.to)) {
            continue;
        }
        visited.insert(path.to);
        mst.emplace_back(path);
        for(auto& ng : graph[path.to]) {
            if(!visited.count(ng.to)) {
                pq.push(ng);
            }
        }
    }
    return mst;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, c1, c2;
        cin >> x >> y >> c1 >> c2;
        graph[x].emplace_back(i, x, y, c1, c2);
        graph[y].emplace_back(i, y, x, c1, c2);
    }
    vector<Path> mst = prim();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& path : mst) {
        if(path.idx != 0) {
            pq.push(path.idx);
        }
    }
    while(pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}


/*
    2.KRUSKAL ALGORITHM
*/

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if(u != parent[u]) {
            return parent[u] = find(parent[u]);
        }
        return u;
    }
    
    void unionSets(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if(ru == rv) {
            return;
        }
        if(size[ru] > size[rv]) {
            parent[rv] = ru;
            size[ru] += size[rv];
        } else {
            parent[ru] = rv;
            size[rv] += size[ru];
        }
    }
};

vector<Path> kruskal(int n, int m, vector<Path>& paths) {
    sort(paths.begin(), paths.end());
    DSU dsu(n);
    vector<Path> mst;
    for(int i = 0; i < m; i++) {
        //cout << paths[i].idx << ' ';
        if(dsu.find(paths[i].from) == dsu.find(paths[i].to)) {
            continue;
        }
        dsu.unionSets(paths[i].from, paths[i].to);
        mst.emplace_back(paths[i]);
        if(mst.size() == n - 1) {
            break;
        }
    }
    return mst;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<Path> paths;
    for(int i = 1; i <= m; i++) {
        int x, y, c1, c2;
        cin >> x >> y >> c1 >> c2;
        paths.emplace_back(i, x, y, c1, c2);
    }
    vector<Path> mst = kruskal(n, m, paths);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& path : mst) {
        pq.push(path.idx);
    }
    while(pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}
