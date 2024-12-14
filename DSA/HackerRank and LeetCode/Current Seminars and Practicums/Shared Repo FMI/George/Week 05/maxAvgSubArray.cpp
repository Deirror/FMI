class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() < k) {
            return 0.;
        }

        double maxAverage = 0.;
        for(int i = 0; i < k; i++) {
            maxAverage += nums[i];
        }
        maxAverage = maxAverage / k;

        double prevAverage = maxAverage;
        for(int i = k, j = 0; i < nums.size(); i++, j++) {
            double currAverage = prevAverage - nums[j] / double(k);
            currAverage += nums[i] / double(k);
            maxAverage = max(maxAverage, currAverage);
            prevAverage = currAverage;
        }
        return maxAverage;
    }
};
