class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> axises;

        for(int i = 0; i < points.size(); i++) {
            axises.insert(points[i][0]);
        }

        int maxDiff = 0;
        int cnt = 0;
        int tempDiff = 0;
        for(auto num : axises) {
            if(cnt % 2 == 1) {
                tempDiff -= num;
                tempDiff *= -1;
                if(tempDiff > maxDiff) {
                    maxDiff = tempDiff;
                }
                cnt++;
            } 

            tempDiff = num;
            cnt++;
        }

        return maxDiff;
    }
};
