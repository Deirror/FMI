#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Path {
    int idx;
    long long from, to;
    long long eff, prize;
    
    Path(int idx, long long from, long long to, long long c1, long long c2) : idx(idx), from(from), to(to), eff(c1) {
        prize = c2;
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

void prim() {
    int n = graph.size();
    
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
        if(path.idx != 0) cout << path.idx << '\n';
        for(auto& ng : graph[path.to]) {
            if(!visited.count(ng.to)) {
                pq.push(ng);
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        long long x, y, c1, c2;
        cin >> x >> y >> c1 >> c2;
        graph[x].emplace_back(i, x, y, c1, c2);
        graph[y].emplace_back(i, y, x, c1, c2);
    }
    prim();
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

void kruskal(int n, int m, vector<Path>& paths) {
    sort(paths.begin(), paths.end());
    DSU dsu(n);
    int counter = 0;
    for(int i = 0; i < m; i++) {
        if(dsu.find(paths[i].from) == dsu.find(paths[i].to)) {
            continue;
        }
        dsu.unionSets(paths[i].from, paths[i].to);
        cout << paths[i].idx << '\n';
        counter++;
        if(counter == n - 1) {
            break;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<Path> paths;
    for(int i = 1; i <= m; i++) {
        long long x, y, c1, c2;
        cin >> x >> y >> c1 >> c2;
        paths.emplace_back(i, x, y, c1, c2);
    }
    kruskal(n, m, paths);
    return 0;
}
