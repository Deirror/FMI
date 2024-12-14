class Solution {
    static bool check(const vector<int>& nums, int test, int goal) {
        int count = 0;
        for(auto num : nums) {
            count += num / test;
            if(num % test != 0) count++;
        }
        return count > goal;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = int(1e5);

        int res = int(1e5);
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(quantities, mid, n)) {
                left = mid + 1;
            } else {
                res = min(res, mid);
                right = mid - 1;
            }
        }

        return res;
    }
};
