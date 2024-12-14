class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> vpq;
        for(int i = 0; i < grid.size(); i++) {
            vpq.emplace_back(priority_queue<int>(grid[i].begin(), grid[i].end()));
        }
        int sum = 0;
        while(vpq[0].size()) {
            int maxNum = 0;
            for(int i = 0; i < vpq.size(); i++) {
                maxNum = max(maxNum, vpq[i].top());
                vpq[i].pop();
            }
            sum += maxNum;
        }
        return sum;
    }
};
