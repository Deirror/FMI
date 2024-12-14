class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while(n) {
            if(n % 2) {
                counter++;
            }
            n /= 2;
        }
        return counter;
    }
};
