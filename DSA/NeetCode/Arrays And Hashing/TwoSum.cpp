class Solution {
public:
    static int search_excl_idx(vector<int>& nums, int target, int idx) {
        for(int i = 0; i < nums.size(); i++) {
            if(i == idx) {
                continue;
            }

            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            int toFind = target - nums[i];
            int resIdx = search_excl_idx(nums, toFind, i);
            if(resIdx != -1) {
                return {min(i,resIdx), max(i,resIdx)};
            }
        }
        return {};
    }
};
