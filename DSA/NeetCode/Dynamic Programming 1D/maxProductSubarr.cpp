class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            res = max(res, cur);
            for (int j = i + 1; j < nums.size(); j++) {
                cur *= nums[j];
                res = max(res, cur);
            }
        }
        
        return res;
    }
};
