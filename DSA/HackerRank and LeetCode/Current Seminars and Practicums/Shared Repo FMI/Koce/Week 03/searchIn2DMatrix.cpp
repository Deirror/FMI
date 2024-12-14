class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size() && matrix[i][0] <= target; i++) {
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(it != matrix[i].end()) {
                if(*it == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
