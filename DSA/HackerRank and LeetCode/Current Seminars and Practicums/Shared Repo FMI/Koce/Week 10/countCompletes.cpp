class Solution {
public:
unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> visited;
    unordered_set<int> nums;
    size_t degrees = 0;
    void dfs(int v) {
        visited.insert(v);
        nums.insert(v);
        degrees += graph[v].size();
        for(auto cv : graph[v]) {
            if(visited.find(cv) == visited.end()) {
                visited.insert(cv);
                dfs(cv);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges){
        for(int i = 0; i < n; i++) {
            graph[i];
        }
        for(auto& v : edges) {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        int completeCount = 0;
        for(int i = 0; i < n; i++) {
            if(visited.find(i) != visited.end()) {
                continue;
            }
            cout << i << "check\n";
            dfs(i);
            int fomulaEdge = nums.size() * (nums.size() - 1)/2;
            if(degrees / 2 == fomulaEdge) {
                cout << i << " YESS\n";
                completeCount++;
            }
            degrees = 0;
            nums.clear();
        }
        return completeCount;
    }
};
