class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int num = nums[0];
        for(int i = 1; i < nums.size() - 1; i+=2) {
            if(num == nums[i]) {
                num = nums[i + 1];
            }  else {
                return num;
            }
        }

        return nums[nums.size() - 1];
    }
};
