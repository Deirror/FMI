class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1,-1};
        if(nums.size() == 0) {
            return result;
        }  
        auto lit = lower_bound(nums.begin(), nums.end(), target);
        auto rit = upper_bound(nums.begin(), nums.end(), target);

        if(lit == nums.end()) {
            return result;
        }

        if(*lit != target) {
            return result;
        } else {
            result[0] = (lit - nums.begin());
            result[1] = (rit - 1 - nums.begin());
            return result;
        }
    }
};
