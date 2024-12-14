class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freqMp;
        unordered_map<int, pair<int, int>> occMp;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freqMp[num]++;
            if(occMp.find(num) != occMp.end()) {
                occMp[num].second = i;
            } else {
                occMp[num] = make_pair(i, i);
            }
        }

        int maxFreq = 0;
        int minDist = INT_MAX;
        for(auto& kvp : freqMp) {
            auto occIdxs = occMp[kvp.first];
            if(kvp.second > maxFreq) {
                maxFreq = kvp.second;         
                minDist = occIdxs.second - occIdxs.first + 1;
            }
            if(kvp.second == maxFreq) {
                minDist = min(minDist, occIdxs.second - occIdxs.first + 1);
            }
        }
        return minDist;
    }
};
