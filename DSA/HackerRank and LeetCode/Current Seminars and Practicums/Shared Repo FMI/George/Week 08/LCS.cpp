class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int longestSeq = 0;
        int currSeq = 0;
        int check = *s.begin() - 1;
        for(auto num : s) {
            if(num - check == 1) {
                currSeq++;
            } else {
                longestSeq = max(longestSeq, currSeq);
                currSeq = 1;
            }
            check = num;
        }
        return  max(longestSeq, currSeq);
    }
};
