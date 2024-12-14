class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int wholeArrayDistinctCount = set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
     
        for(int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> curr;

            for(int j = i; j < nums.size(); j++)
            {
                curr.insert(nums[j]);

                if(curr.size()==wholeArrayDistinctCount)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
