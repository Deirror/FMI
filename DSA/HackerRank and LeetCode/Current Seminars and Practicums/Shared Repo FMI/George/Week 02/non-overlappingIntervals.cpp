class Solution {
    static bool compare(const vector<int>& lhs, const vector<int>& rhs) {
        if(lhs[1] == rhs[1]) {
            return lhs[0] < rhs[0];
        }

        return lhs[1] < rhs[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;
        int lastEndTime = -100000;

        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if (start >= lastEndTime) {
                count++;
                lastEndTime = end;
            }
        }

        return intervals.size() - count;
    }
};
