class Solution {
public:
    bool hasPath(int source, int destination, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
        visited.insert(source);
        for(auto cv : graph[source]) {
            if(cv == destination) {
                return true;
            }
            if(visited.find(cv) == visited.end()) {
                visited.insert(cv);
                if(hasPath(cv, destination, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.empty()) {
            return true;
        }
        unordered_map<int, unordered_set<int>> graph;
        for(auto& v : edges) {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        unordered_set<int> visited;
        return hasPath(source, destination, graph, visited);
    }
};
