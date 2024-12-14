class Solution {
    static int check(const vector<int>& nums, int test) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(test <= nums[i]) {
                count++;
            }
        }

        if(count > test) {
            return 1;
        } else if (count == test) {
            return 0;
        }
        
        return -1;
    }
public:
    int specialArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size();

        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            int ch_res = check(nums, mid);
            if(ch_res == 0) {
                return mid;
            }
            else if(ch_res == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
