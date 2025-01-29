class Solution {
public:
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
                parent[u] = find(parent[u]);
            }
            return parent[u];
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

    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }
        set<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(dsu.find(i) == dsu.find(j)) continue;
                auto pr = make_pair(min(i, j), max(i, j));
                if(!s.count(pr)) {
                    s.insert(pr);
                }
            }
        }
        return s.size();
    }
};
