class Solution {
public:
    void dfs(int v, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited) {
        visited[v] = true;
        for(auto cv : graph[v]) {
            if(!visited[cv]) {
                visited[cv] = true;
                dfs(cv, graph, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, unordered_set<int>> graph;
        size_t n = isConnected.size();
		for (size_t i = 0; i < n; i++) {
			for (size_t j = i; j < n; j++) {
				if (isConnected[i][j]) {
					graph[i + 1].insert(j + 1);
                    graph[j + 1].insert(i + 1);
				}
			}
		}
        vector<bool> visited(n + 1);
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                continue;
            }
            dfs(i, graph, visited);
            count++;
        }
        return count;
    }
};
