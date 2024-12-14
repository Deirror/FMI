class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto pos = upper_bound(nums.begin(), nums.end(), 0);
        auto neg = upper_bound(nums.begin(), nums.end(), -1);
        return max((nums.end() - pos), (neg - nums.begin()));
    }
};
