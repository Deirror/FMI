class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        int maxNum = 1;
        for(auto& v : edges) {
            maxNum = max(maxNum, max(v[0], v[1]));
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        for(auto& kvp : graph) {
            if(kvp.second.size() == maxNum - 1) {
                return kvp.first;
            }
        }
        return -1;
    }
};
