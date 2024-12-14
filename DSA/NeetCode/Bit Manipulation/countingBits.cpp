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

    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++) {
            res[i] = hammingWeight(i);
        }
        return res;
    }
};
