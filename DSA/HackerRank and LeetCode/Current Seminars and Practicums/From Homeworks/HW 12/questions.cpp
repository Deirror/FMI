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
        for(int i = 0; i <= n; i++){
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
        ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--) {
        int x, y;
        cin >> x >> y;
        dsu.unionSets(x, y);
    }
    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
      //SWITCHES DON'T WORK IN HACKERRANK
        if(t == 1) {
            cout << (dsu.find(x) == dsu.find(y));
        }
        else if(t == 2){
            dsu.unionSets(x, y);
        }
    }
    return 0;
}
