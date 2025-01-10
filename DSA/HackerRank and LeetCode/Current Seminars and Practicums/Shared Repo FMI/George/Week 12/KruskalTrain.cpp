struct Edge {
    int from, to, weight;
    
    Edge(int from, int to, int weight) 
     : from(from), to(to), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) {
            return false;
        }
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int edgesCount = g_from.size();
    priority_queue<Edge> pq;
    for(int i = 0; i < edgesCount; i++) {
       pq.push(Edge(g_from[i], g_to[i], g_weight[i]));
    }
    DSU dsu(g_nodes);
    int i = 0;
    int sum = 0;
    while(pq.size() && i < g_nodes - 1) {
        auto edge = pq.top();
        pq.pop();
        if(dsu.unionSets(edge.from, edge.to)) {
            sum += edge.weight;
            i++;
        }
    }
    return sum;
}
