class Solution {
public:
vector<vector<int>> res;
unordered_set<int> visited;
    void findPath(int vertex, int target, vector<vector<int>>& graph, vector<int>& path) {
        path.push_back(vertex);
        if(vertex == target) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        visited.insert(vertex);
        for(auto& v : graph[vertex]) {
            if(visited.find(v) == visited.end()) {
                findPath(v, target, graph, path);
            }
        }
        visited.erase(vertex);
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int maxNum = 0;
        for(auto& v : graph) {
            if(v.size()) {
                maxNum = max(maxNum, *max_element(v.begin(), v.end()));
            }
        }
        vector<int> path;
        findPath(0, maxNum, graph, path);
        return res;
    }
};
