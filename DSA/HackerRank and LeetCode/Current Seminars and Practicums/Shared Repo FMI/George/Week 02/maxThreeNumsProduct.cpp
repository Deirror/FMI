class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int SIZE = nums.size();

        int potentialMaxProduct = INT_MIN;
        int negativeMaxProduct = INT_MIN;
        if(nums[0] < 0 && nums[1] < 0 && nums[SIZE - 1] >= 0) {
            nums[0] *= -1;
            nums[1] *= -1;
            potentialMaxProduct = nums[0] * nums[1] * nums[SIZE - 1];
        } else if (nums[0] < 0 && nums[1] < 0 && nums[2] < 0){
            negativeMaxProduct = nums[0] * nums[1] * nums[2];
        }

        int maxNum =  max(negativeMaxProduct, max(potentialMaxProduct, nums[SIZE - 1] * nums[SIZE - 2] * nums[SIZE- 3]));
        return maxNum;
    }
};
