class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] && 
                                    (i + 1 > (i + l - 2) || 
                                    dp[i + 1][i + l - 2]));
            }
        }
        
        return dfs(s, dp, 0);
    }

    vector<vector<string>> dfs(string& s, vector<vector<bool>>& dp, int i) {
        if (i >= s.size()) {
            return {{}};
        }

        vector<vector<string>> ret;
        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                auto nxt = dfs(s, dp, j + 1);
                for (auto& part : nxt) {
                    vector<string> cur;
                    cur.push_back(s.substr(i, j - i + 1));
                    cur.insert(cur.end(), part.begin(), part.end());
                    ret.push_back(cur);
                }
            }
        }
        return ret;
    }
};
