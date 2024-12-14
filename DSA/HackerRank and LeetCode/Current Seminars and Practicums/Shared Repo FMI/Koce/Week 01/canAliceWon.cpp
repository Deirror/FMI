class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int digitSum = 0;
        int numSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 10) {
                digitSum += nums[i];
            }
            else
             {
                numSum += nums[i];
             }
        }

        return (numSum != digitSum);
    }
};
