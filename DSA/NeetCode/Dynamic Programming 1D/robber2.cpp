class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        int prev1 = 0, prev2 = 0;
        int maxRobber = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            int temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }
        maxRobber = prev1;
        prev1 = 0;
        prev2 = 0;
         for(int i = 1; i < nums.size(); i++) {
            int temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }
        return max(maxRobber, prev1);
    }
};
