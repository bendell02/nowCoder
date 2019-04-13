class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty()) { return; }
 
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> cols_zeros(cols, false);
        int count_row = 0;
        // swipe rows
        for (int i = 0; i < rows; ++i) {
            count_row = 0;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != 0) {
                    ++count_row;
                }
                else {
                    cols_zeros[j] = true;
                }
            }
            if (count_row != cols) {
                matrix[i] = vector<int>(cols, 0);
            }
        }
 
        // swipe cols
        for (int j = 0; j < cols; ++j) {
            if (cols_zeros[j]) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
