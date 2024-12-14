class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int lastNum = nums[nums.size() - 1];
        int lastButOneNum = nums[nums.size() - 2];

        return (lastNum - 1) * (lastButOneNum - 1);
    }
};
