class Solution {
    bool compare(const auto& lhs, const auto& rhs) {
        if(lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }

        return lhs[0] < rhs[0];
    }
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());

        int counter = 1;
        int firstPointX = points[0][0];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] - firstPointX > w) {
                counter++;
                firstPointX = points[i][0];
            }
        }

        return counter;
    }
};
