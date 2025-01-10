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
    
    int find(int u){
        if(u != parent[u]) {
            return parent[u] = find(parent[u]);
        }
        return u;
    }
    
    bool isSameSet(int u, int v) {
        return find(u) == find(v);
    }
    
    void unionSets(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if(ru == rv) {
            return;
        }
        if(size[ru] > size[rv]) {
            parent[rv] = ru;
            size[ru]+=size[rv];
        } else {
            parent[ru] = rv;
            size[rv] += size[ru];
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    DSU dsu(n);
    int u, v;
    while(cin >> u >> v) {
        if(dsu.isSameSet(u, v)) {
            cout << n << " CYCLE FORMED!\n";
        } else {
            dsu.unionSets(u, v);
            cout << --n << '\n';
        }
    }
    return 0;
}
