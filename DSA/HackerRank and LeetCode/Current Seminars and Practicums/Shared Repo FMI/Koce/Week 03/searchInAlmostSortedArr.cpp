class Solution {
    static size_t binary_search_idx(vector<int>& nums, int low, int high,int target) {
        int left = low;
        int right = high;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(nums[0] == target) {
                return 0;
            }

            return -1;
        }

        auto pivot_idx = min_element(nums.begin(), nums.end());

        int idx1 = binary_search_idx(nums, 0, pivot_idx - nums.begin(), target);
        int idx2 = binary_search_idx(nums, pivot_idx - nums.begin(), nums.size() - 1, target);

        if(idx1 != -1) {
            return idx1;
        } else if (idx2 != -1) {
            return idx2;
        } else {
            return -1;
        }
    }
};
