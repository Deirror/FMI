#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--) {
        int x, y;
        cin >> x >> y;
        dsu.unionSets(x, y);
    }
    int k;
    cin >> k;
    while(k--) {
        int x, y;
        cin >> x >> y;
        cout << (dsu.find(x) == dsu.find(y)) << ' ';
    }
    return 0;
}
