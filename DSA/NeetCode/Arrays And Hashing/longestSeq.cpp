class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int maxSeq = 1;
        int currMax = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                continue;
            }

            if(nums[i] - nums[i + 1] == -1) {
                currMax++;
            } else {
                maxSeq = max(maxSeq, currMax);
                currMax = 1;
            }
        }
        maxSeq = max(maxSeq, currMax);
        return maxSeq;
    }
};
