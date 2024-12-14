class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> pairNums(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            pairNums[i].first = nums[i];
            pairNums[i].second = i;
        }

        sort(pairNums.begin(), pairNums.end());

        int diff = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(pairNums[i].first == pairNums[i + 1].first &&
               abs(pairNums[i].second - pairNums[i + 1].second) <= k) {
                return true;
            }
        }

        return false;
    }
};
