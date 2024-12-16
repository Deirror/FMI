class Solution {
public:
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> visited;

    unordered_set<int> rest;

    int count = 0;

    void dfs(int v) {
        visited.insert(v);
        count++;
        for(auto cv : graph[v]) {
            if(rest.count(cv)) continue;
            if(visited.count(cv) == 0) dfs(cv);
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        rest = unordered_set<int>(restricted.begin(), restricted.end());
        dfs(0);
        return count;
    }
};
