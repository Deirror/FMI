class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> count;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> cur;
        vector<int> A;
        for (int num : nums) {
            if (!count[num]) {
                A.push_back(num);
            }
            count[num]++;
        }
        backtrack(A, target, cur, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        if (count[nums[i]]) {
            cur.push_back(nums[i]);
            count[nums[i]]--;
            backtrack(nums, target - nums[i], cur, i);
            count[nums[i]]++;
            cur.pop_back();
        }

        backtrack(nums, target, cur, i + 1);
    }
};
