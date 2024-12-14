class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long dp[amount + 1]{};
        for(int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            vector<long long> res = {INT_MAX};
            for(auto coin : coins) {
                if(i >= coin) {
                    res.push_back(dp[i - coin]);
                }
            }

            dp[i] = *min_element(res.begin(), res.end()) + 1;
        }

        return dp[amount] >= INT_MAX ? -1 : dp[amount];
    }
};
