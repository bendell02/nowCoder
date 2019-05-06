class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int> > res;
        vector<int> layout(n, -1);
        dfs(layout, 0, res, n);
 
        vector<vector<string> > resQ;
        convert(res, resQ, n);
        return resQ;
    }
 
    void convert(vector<vector<int> > &res, vector<vector<string> > &resQ, int &n) {
        string basic = "";
        for (int i = 0; i < n; ++i) { basic += '.'; }
 
        int nums = res.size();
        resQ.resize(nums, vector<string>(n, basic));
        for (int i = 0; i < nums; ++i) {
            for (int j = 0; j < n; ++j) {
                resQ[i][j][res[i][j]] = 'Q';
            }
        }
    }
 
    void dfs(vector<int> &layout, int row, vector<vector<int> > &res, int &n) {
        if (row == n) { res.push_back(layout); }
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
