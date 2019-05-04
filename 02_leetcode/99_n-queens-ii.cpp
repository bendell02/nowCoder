class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> layout(n, -1);
        dfs(layout, 0, res, n);

        return res;
    }

    void dfs(vector<int> &layout, int row, int &res, int &n) {
        if (row == n) { ++res; }
        else {
            for (int i = 0; i < n; ++i) {
                if (isValid(layout, row, i, n)) {
                    layout[row] = i;
                    dfs(layout, row + 1, res, n);
                    layout[row] = -1;
                }
            }
        }
    }

    bool isValid(vector<int> &layout, int &row, int &col, int &n) {
        for (int i = 0; i < row; ++i) {
            if ((layout[i] == col) || (std::abs(row - i) == std::abs(col - layout[i]))) {
                return false;
            }
        }

        return true;
    }
};
