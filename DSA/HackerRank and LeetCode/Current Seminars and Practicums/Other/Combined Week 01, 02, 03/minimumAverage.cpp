class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int size = nums.size() / 2;
        vector<float> resAvg;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; i++) {
            resAvg.push_back((float(nums[i] + nums[nums.size() - 1 -i]) / 2));
        }

        return *std::min_element(resAvg.begin(),resAvg.end());
    }
};
