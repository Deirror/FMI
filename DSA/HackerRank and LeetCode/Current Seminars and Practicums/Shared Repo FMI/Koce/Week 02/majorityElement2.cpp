class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int times = nums.size() / 3;

        sort(nums.begin(), nums.end());

        int counter = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                counter++;
            } else {
                if(counter > times) {
                    result.push_back(nums[i]);
                }
                counter = 1;
            }
        }

        if(counter > times) {
            result.push_back(nums[nums.size() - 1]);
        }

        return result;
    }
};
