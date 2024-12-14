class Solution {
    static bool check(vector<int>& dist, int test, double goal) {
        int res = 0;
        for(int i = 0; i < dist.size() - 1; i++) {
            res += dist[i] / test;
            if(dist[i] % test > 0) {
                res++;
            }
        }
        double fl_res = double(res + dist[dist.size() - 1] / double(test));
        return fl_res <= goal;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = int(1e7);

        int res = right + 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(dist, mid, hour)) {
                res = min(mid, res);
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        return (res == int(1e7) + 1? -1 : res);
    }
};
