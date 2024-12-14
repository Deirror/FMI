class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        while(left <= right) {
            long long res = left*left + right*right;
            if(res == c) {
                return true;
            } else if(res < c) {
                left++;
            } else {
                right--;
            }
        }

        return false;
    }
};
