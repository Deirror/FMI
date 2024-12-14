class Solution {
public:
    int dp[31] {0, 1, 2};
    int climbStairs(int n) {
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
