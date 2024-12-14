class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size() - 1;

        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int count = citations.size() - mid;

            if(count > citations[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
                res = max(res, count);
            }
        }

        return res;
    }
};
