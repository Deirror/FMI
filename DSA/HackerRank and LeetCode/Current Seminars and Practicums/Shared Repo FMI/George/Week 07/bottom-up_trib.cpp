class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 || n == 1) {
            return n;
        } else if(n == 2) {
            return 1;
        }
        int res = 0;
        int fNum = 0;
        int sNum = 1;
        int tNum = 1;
        for(int i = 3; i <= n; i++) {
            res = fNum + sNum + tNum;
            fNum = sNum;
            sNum = tNum;
            tNum = res;
        }
        return res;
    }
};
