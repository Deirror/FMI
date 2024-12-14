class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(um.find(nums[i]) != um.end()) {
                res += um[nums[i]];
            }
            um[nums[i]]++;
        }
        return res;
    }
};
