class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) { return {}; }

        int m = matrix.size();
        int n = matrix[0].size();
        int len = m * n;
        vector<vector<bool> > flag(m, vector<bool>(n, false));
        int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        int x = 0, y = 0, k = 0;
        vector<int> result;
        for (int t = 0; t < len; ++t) {
            result.push_back(matrix[y][x]);
            flag[y][x] = true;
            for (int t = 0; t < 4; t++) {
                if (isValid(y + direction[k][1], x + direction[k][0], m, n, flag)) {
                    y = y + direction[k][1];
                    x = x + direction[k][0];
                    break;
                }
                k = (k + 1) % 4;
            }
        }

        return result;
    }

    bool isValid(int i, int j, int &m, int &n, vector <vector<bool> > &flag) {
        if (i < 0 || i >= m || j < 0 || j >= n || (true == flag[i][j])) {
            return false;
        }

        return true;
    }
};
