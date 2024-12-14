class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &grid, int empty) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[row][col] == 2) {
            if (empty == 0) {
                return 1;
            }
            return 0;
        }

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        grid[row][col] = -1;
        int paths = 0;
        for (int i = 0 ; i < 4 ; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] != -1) {
                paths += solve(nRow, nCol, grid, empty-1);
            }
        }
        grid[row][col] = 0;

        return paths;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int sX = 0, sY = 0, empty = 1;

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1) {
                    sX = i;
                    sY = j;
                }
                else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        return solve(sX, sY, grid, empty);
    }
};
