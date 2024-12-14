class Solution {
public:
    int bsearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right  = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if(nums[0] < nums[nums.size() - 1]) {
            return bsearch(nums, target);
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            if(nums[mid] < nums[0]) {
                if(nums[mid] < target) {
                    if(target >= nums[0]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    right = mid - 1;
                }
            } else {
                if(nums[mid] > target) {
                    if(target < nums[0]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
