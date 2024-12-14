class Solution {
public:
    bool check(vector<int>& piles, int test, int goal) {
        int res = 0;
        for(auto pile : piles) {
            res += pile / test;
            if(pile % test != 0) {
                res++;
            }
        }
        return res <= goal;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = *max_element(piles.begin(), piles.end());

        int left = 1;
        int right = ans;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(piles, mid, h)) {
                right = mid - 1;
                ans = min(ans, mid);
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
