class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int maxDiff = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            int currDiff = std::abs(nums[i] - nums[i + 1]);
            if(currDiff > maxDiff) {
                maxDiff = currDiff;
            }
        }

        return maxDiff;
    }
};
