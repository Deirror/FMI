class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int min = *min_element(nums.begin(),nums.end());
        int offset = 0;
        if(min < 0) {
            offset = min * (-1);
        }
        int hist[2*1000 + 1]{};

        for(auto num : nums) {
            hist[offset + num]++;
        }

        for(int i = 0; i < k; i++) {
            auto maxIt = max_element(hist, hist + 2001);
            result.push_back((maxIt - hist) - offset);
            *maxIt = 0;
        }

        return result;
    }
};
