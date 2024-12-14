class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int productWithoutZero = 1;
        int zeroCount = 0;
        for(auto num : nums) {
            product *= num;
            if(num) {
                productWithoutZero *= num;
            } else {
                zeroCount++;
            }
        }

        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) {
                if(zeroCount == 1)
                res.push_back(productWithoutZero);
                else
                res.push_back(0);
            } else {
                res.push_back(product / nums[i]);
            }
        }

        return res;
    }
};
