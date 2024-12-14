class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        auto beg = numbers.begin();
        auto end = numbers.end() - 1;

        while(beg < end) {
            int sum = *beg + *end;
            if(sum == target) {
                return {beg - numbers.begin() + 1, end - numbers.begin() + 1};
            }

            if(sum > target) {
                end--;
            } else {
                beg++;
            }
        }
        return {};
    }
};
