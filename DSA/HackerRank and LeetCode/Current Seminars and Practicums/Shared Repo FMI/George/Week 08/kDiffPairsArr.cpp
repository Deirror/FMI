class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(auto num : nums) {
            um[num]++;
        }
        int res = 0;
        unordered_set<int> us(nums.begin(), nums.end());
        for(auto num : us) {
            if(um.find(num + k) != um.end()) {
                if(!k) {
                    if(um[num] > 1) {
                        res++;
                    }
                } else {
                    res++;
                }
            }
        }
        return res;
    }
};
