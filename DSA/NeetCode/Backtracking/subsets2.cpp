class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(!nums.size()) {
            return {};
        }
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            int size = res.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }

        set<vector<int>> remDup;
        for(auto& s : res) {
            sort(s.begin(), s.end());
            remDup.insert(s);
        }

        res.clear();
        for(auto& s : remDup) {
            res.emplace_back(s);
        }

        return res;
    }
};
