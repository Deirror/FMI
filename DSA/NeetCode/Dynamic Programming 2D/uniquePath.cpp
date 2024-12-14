class Solution {
public:
    int dfs(vector<vector<int>>& dp, int i, int j) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(!i && !j) {
            return 1;
        }

        if(dp[i][j] > 0) {
            return dp[i][j];
        }
        return dp[i][j] = dfs(dp, i - 1, j) + dfs(dp, i, j - 1);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, false));
        dp[m - 1][n - 1] = dfs(dp, m - 1, n - 1);
        return dp[m - 1][n - 1];
    }
};
