class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        
        int target = sum / 2;
        bitset<10001> dp; 
        dp[0] = 1;

        for (int num : nums) {
            dp |= dp << num;
        }

        return dp[target];
    }
};
