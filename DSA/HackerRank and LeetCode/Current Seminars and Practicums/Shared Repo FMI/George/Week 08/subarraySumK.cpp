class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int res = 0;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            if(prefix[i] == k) {
                res++;
            }
            if(um.find(prefix[i] - k) != um.end()) {
                res += um[prefix[i] - k];
            }
            um[prefix[i]]++;
        }
        return res;
    }
};
