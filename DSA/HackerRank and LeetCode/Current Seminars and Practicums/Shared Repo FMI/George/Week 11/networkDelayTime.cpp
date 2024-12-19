class Solution {
public:
    vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for(size_t i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(pq.size()) {
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(cost > dist[v]) {
            continue;
        }
        for(auto& cv : graph[v]) {
            int ch = cv.first;
            int chCost = cv.second;
            if(dist[ch] > dist[v] + chCost) {
                dist[ch] = dist[v] + chCost;
                pq.push({dist[ch], ch});
            }
        }
    }
    dist.erase(dist.begin() + s);
    dist.erase(dist.begin());
    for(size_t i = 0; i < dist.size(); i++) {
        if(dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }
    return dist;
}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist = shortestReach(n, times, k);
        if(find(dist.begin(), dist.end(), -1) != dist.end()) {
            return -1;
        }
        return *max_element(dist.begin(), dist.end());
    }
};
