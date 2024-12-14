class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        if(nums[0] <= nums[nums.size() - 1]) {
            return nums[0];
        }

        int ans = 1000;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[0]) {
                right = mid - 1;
                ans = min(ans, nums[mid]);
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
