class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum = 0;

        int size = s.length();
        for(int i = 0; i < size; i++) {
            char searched = s[i];
            for(int j = 0; j < size; j++) {
                if(searched == t[j]) {
                    sum += std::abs(i - j);
                }
            }
        }

        return sum;
    }
};
