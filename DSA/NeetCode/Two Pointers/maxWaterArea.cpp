class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxRes = 0;
        auto beg = heights.begin();
        auto end = heights.end() - 1;
        while(beg < end) {
            int currRes = (end - beg) * min(*beg, *end);
            maxRes = max(maxRes, currRes);
            if(*beg < *end) {
                beg++;
            } else {
                end--;
            }
        }
        return maxRes;
    }
};
