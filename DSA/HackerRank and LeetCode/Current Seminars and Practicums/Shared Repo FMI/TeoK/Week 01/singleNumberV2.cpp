class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int num = nums[0];
        for(int i = 2; i < nums.size(); i+=3) {
            if(num == nums[i - 1] && nums[i - 1] == nums[i]) {
                num = nums[i + 1];
            }  else {
                return num;
            }
        }

        return nums[nums.size() - 1];
    }
};
