class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long dp[301][5001]{0};
        for(int i = 0; i < 301; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i - 1] >= 0) {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i - 1]]) % (1000000000000000);
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
