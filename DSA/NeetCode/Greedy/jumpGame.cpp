class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for(int i = goal - 1; i >= 0; i--) {
            if(nums[i] + i >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
