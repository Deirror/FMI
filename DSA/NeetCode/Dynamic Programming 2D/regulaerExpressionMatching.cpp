class Solution {
    vector<vector<int>> dp;

public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s, p, m, n);
    }

private:
    bool dfs(int i, int j, string& s, string& p, int m, int n) {
        if (j == n) {
            return i == m;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < n && p[j + 1] == '*') {
            dp[i][j] = dfs(i, j + 2, s, p, m, n) || 
                       (match && dfs(i + 1, j, s, p, m, n));
        } else {
            dp[i][j] = match && dfs(i + 1, j + 1, s, p, m, n);
        }
        return dp[i][j];
    }
};
