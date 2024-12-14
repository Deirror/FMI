class Solution {
    int hist[2*int(1e4) + 3]{};
public:
    int findKthLargest(vector<int>& nums, int k) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        int offset = 0;
        if(min < 0) {
            offset = (-1) * min;
        }

        for(int i = 0; i < nums.size(); i++) {
            hist[offset + nums[i]]++;
        }

        int counter = 0;
        for(int i = max; i >= min; i--) {
            if(hist[offset + i] > 0) {
                counter += hist[offset + i];
            }

            if(counter >= k) {
                return i;
            }
        }

        return -1;
    }
};
