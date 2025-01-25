#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
        if(parent[u] != u) {
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
    int v, e;
    cin >> v >> e;
    DSU dsu(v);
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unionSets(x, y);
    }
    unordered_map<int, int> um;
    for(int i = 0; i < v; i++) {
        um[dsu.find(i)]++;
    }
    int count = 0;
    for(auto& x : um) {
        if(x.second > 1) {
            count++;
        }
    }
    cout << count;
    return 0;
}
