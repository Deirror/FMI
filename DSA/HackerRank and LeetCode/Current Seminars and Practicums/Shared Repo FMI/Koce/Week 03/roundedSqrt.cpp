class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }

        for(size_t i = 0; i <= x; i++) {
            size_t pow = size_t(i * i);
            if(pow > x) {
                return i - 1;
            }
       } 
       return 1;
    }
};
