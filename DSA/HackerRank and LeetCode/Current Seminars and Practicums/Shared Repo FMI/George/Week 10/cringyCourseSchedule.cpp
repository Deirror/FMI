class Solution {
public:
vector<int> res;

bool dfs(int v, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, unordered_set<int>& toDelete) {
    if(visited.find(v) != visited.end() || toDelete.find(v) != toDelete.end()) {
        return false;
    }
    visited.insert(v);
    for(auto cv : graph[v]) {
        if(visited.find(cv) != visited.end() && toDelete.find(cv) != toDelete.end()) {
            continue;
        } else if(visited.find(cv) != visited.end() && toDelete.find(cv) == toDelete.end()) {
            return true;
        }
        if(dfs(cv, graph, visited, toDelete)) {
            return true;
        }
    }
    toDelete.insert(v);
    return false;
}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) {
            for(int i = numCourses - 1; i >= 0; i--) {
                res.push_back(i);
            }
            return res;
        }
        int maxNum = -1;
        unordered_set<int> first, second;
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> allNums;
        for(auto& v : prerequisites) {
            allNums.insert(v[0]);
            allNums.insert(v[1]);
            first.insert(v[0]);
            second.insert(v[1]);
            graph[v[1]].insert(v[0]);
            maxNum = max(maxNum, max(v[1], v[0]));
        }
        for(auto v : first) {
            second.erase(v);
        }
        if(second.empty()) {
            return {};
        }
        int sv = *second.begin();
        second.erase(sv);
        for(auto v : second) {
            res.push_back(v);
        }
        for(int i = numCourses - 1; i >= 0; i--) {
            if(allNums.find(i) == allNums.end()) {
                res.push_back(i);
            }
        }
        unordered_set<int> visited;
        unordered_set<int> toDelete;
        if(dfs(sv, graph, visited, toDelete)) {
            return {};
        }
        visited.clear();
        queue<int> q;
        q.push(sv);
        visited.insert(sv);
        while(q.size()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                int v = q.front();
                res.push_back(v);
                for(auto cv : graph[v]) {
                    if(visited.find(cv) == visited.end()) {
                        visited.insert(cv);
                        q.push(cv);                  
                    }
                }
                q.pop();
            }
        }
        return res;
    }
};
