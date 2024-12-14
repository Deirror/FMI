class Solution {
public:
    void dfs(int v, vector<vector<int>>& rooms, unordered_set<int>& visited) {
        visited.insert(v);
        for(auto cv : rooms[v]) {
            if(visited.find(cv) == visited.end()) {
                visited.insert(cv);
                dfs(cv, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(0, rooms, visited);
        return rooms.size() == visited.size();
    }
};
