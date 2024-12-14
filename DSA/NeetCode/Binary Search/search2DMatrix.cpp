class Solution {
public:
    int lower_bound_firstCol(const vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size();     
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target) {
            return false;
        }

        if(matrix.size() == 1) {
             return binary_search(matrix[0].begin(), matrix[0].end(), target);
        }

        int idx = lower_bound_firstCol(matrix, target);

        if(idx == matrix.size()) {
            return binary_search(matrix[idx - 1].begin(), matrix[idx - 1].end(), target);
        }

        if(matrix[idx][0] == target) {
            return true;
        } else {
            return binary_search(matrix[idx - 1].begin(), matrix[idx - 1].end(), target);
        }
    }
};
