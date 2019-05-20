class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) { return; }
 
        dfs(board, 0, 0);
    }
 
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 9) { return true; }
        if (j >= 9) { return dfs(board, i + 1, 0); }
 
        if ('.' == board[i][j]) {
            for (int k = 0; k < 9; ++k) {
                board[i][j] = char(k + '1');
                if (isValid(board, i, j)) {
                    if (dfs(board, i, j + 1)) { return true; }
                }
                board[i][j] = '.';
            }
        }
        else {
            return dfs(board, i, j + 1);
        }
 
        return false;
    }
 
    bool isValid(vector<vector<char>>& board, int i, int j) {
        for (int col = 0; col < 9; ++col) {
            if (col != j && board[i][col] == board[i][j]) { return false; }
        }
 
        for (int row = 0; row < 9; ++row) {
            if (row != i && board[row][j] == board[i][j]) { return false; }
        }
 
        int row_start = 3 * (i / 3);
        int col_start = 3 * (j / 3);
        for (int row = row_start; row < row_start + 3; ++row) {
            for (int col = col_start; col < col_start + 3; ++col) {
                if ((row != i || col != j) && board[i][j] == board[row][col]) { return false; }
            }
        }
 
        return true;
    }
};
