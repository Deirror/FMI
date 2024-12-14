class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int shift = 31;
        while(n) {
            bool bit = n % 2;
            n /= 2;
            res |= (bit << shift);
            shift--;
        }
        return res;
    }
};
