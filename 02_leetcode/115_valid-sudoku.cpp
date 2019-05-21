class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int LENGTH = 9;
        vector<vector<bool> > rowFlag(LENGTH, vector<bool>(LENGTH, false));
        vector<vector<bool> > colFlag(LENGTH, vector<bool>(LENGTH, false));
        vector<vector<bool> > gridFlag(LENGTH, vector<bool>(LENGTH, false));
 
        for (int i = 0; i < LENGTH; ++i) {
            for (int j = 0; j < LENGTH; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int num = int(board[i][j] - '1');
                    int gridIndex = (3 * (i / 3) + (j / 3));
                    if (rowFlag[i][num] || colFlag[j][num] || gridFlag[gridIndex][num]) {
                        return false;
                    }
                    rowFlag[i][num] = true;
                    colFlag[j][num] = true;
                    gridFlag[gridIndex][num] = true;
                }
            }
        }
 
        return true;
    }
};
