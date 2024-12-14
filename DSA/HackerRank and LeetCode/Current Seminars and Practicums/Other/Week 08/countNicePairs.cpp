class Solution {
public:
    int rev(int x) {
        int res = 0;
        while(x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    const int MOD = int(1e9) + 7;
    int countNicePairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            res = (res + um[nums[i] - rev(nums[i])]) % MOD;
            um[nums[i] - rev(nums[i])]++;
        }
        return res;
    }
};
