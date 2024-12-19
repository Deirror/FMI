#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> ways(n + 1, 0);
    dist[1] = 0;
    ways[1] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    if (dist[n] == LLONG_MAX) {
        cout << "-1 0\n";
    } else {
        cout << dist[n] << " " << ways[n] << "\n";
    }
}

int main() {
    solve();
    return 0;
}
