class Solution {
public:
    int col = 0, posDiag = 0, negDiag = 0;
    vector<string> board;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        
        backtrack(0, n);
        return res;
    }

    void backtrack(int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if ((col & (1 << c)) || (posDiag & (1 << (r + c)))
                 || (negDiag & (1 << (r - c + n)))) {
                continue;
            }
            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            board[r][c] = 'Q';

            backtrack(r + 1, n);

            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            board[r][c] = '.';
        }
    }
};
