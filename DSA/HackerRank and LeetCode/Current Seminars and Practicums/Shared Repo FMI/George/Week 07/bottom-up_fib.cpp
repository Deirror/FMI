class Solution {
public:
    int fib(int n) {
        int res = n;
        int fNum = 0;
        int sNum = 1;
        for(int i = 2; i <= n; i++) {
            res = fNum + sNum;
            fNum = sNum;
            sNum = res;
        }
        return res;
    }
};
