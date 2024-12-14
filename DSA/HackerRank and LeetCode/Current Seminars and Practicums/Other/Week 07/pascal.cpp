class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int dp[30][30]{};
        for(int i = 0; i < numRows; i++) {
            dp[0][i] = 1;
            dp[i][0] = 1;
        }
        for(int i = 1; i < numRows; i++) {
            for(int j = 1, t = i; j <= i && t > 0; j++, t--) {
                dp[t][j] = dp[t][j - 1] + dp[t - 1][j];
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> temp;
            for(int j = 0, t = i; j <= i && t >= 0; j++, t--) {
                temp.push_back(dp[t][j]);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};
