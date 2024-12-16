class Solution {
public:
    unordered_map<int, unordered_set<int>> graph;
    bool isConnected() {
        unordered_set<int> visited;
        queue<int> q;
        q.push((*graph.begin()).first);
        visited.insert((*graph.begin()).first);
        while(q.size()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                int fv = q.front();
                q.pop();
                for(auto cv : graph[fv]) {
                    if(!visited.count(cv)) {
                        q.push(cv);
                        visited.insert(cv);
                    }
                }
            }
        }
        return visited.size() == graph.size();
    }

    unordered_set<int> checked;
    bool isAcyclic(int v, int parent) {
        if(v == parent) {
            return  false;
        }
        checked.insert(v);
        for(auto cv : graph[v]) {
            if(cv == parent) {
                continue;
            }
            if(checked.count(cv)) {
                return false;
            }
            if(!isAcyclic(cv, v)) {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return true;
        for(auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        return isConnected() && isAcyclic((*graph.begin()).first, -1);
    }
};
