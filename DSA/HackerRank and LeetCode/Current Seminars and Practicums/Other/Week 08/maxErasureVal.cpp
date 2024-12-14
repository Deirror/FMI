class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> us;
        int currSum = 0;
        int maxSum = 0;
        int leftMost = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(us.find(nums[i]) != us.end()) {
                currSum -= nums[leftMost];
                us.erase(nums[leftMost++]);
            }
            currSum += nums[i];
            us.insert(nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
