class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> out(n + 1, -1);
        vector<int> in(n + 1, -1);
        for(auto& v : edges) {
            out[v[0]]++;
            in[v[1]]++;
        }
        int count = -1;
        for(int i = 0; i < n; i++) {
            if(in[i] == -1) {
                if(count != -1) return -1;
                count = i;
            }
        }
        return count;
    }
};
