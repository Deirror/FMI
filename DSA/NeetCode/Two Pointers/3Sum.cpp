class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                int target = (-1) * (nums[i] + nums[j]);
                auto beg = j + 1 + nums.begin();
                bool flag = false;
                while(beg != nums.end()) {
                    if(target == *beg) {
                        flag = true;
                        break;
                    }
                    beg++;
                }
                if(flag) {
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    if(!res.size()) {
                        res.emplace_back(temp);
                    } else {
                        if(find(res.begin(), res.end(), temp) == res.end()) {
                            res.emplace_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};
