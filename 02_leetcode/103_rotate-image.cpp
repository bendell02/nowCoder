class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int half_row = n / 2;
        int half_col = (n + 1) / 2;
 
        int temp = 0;
        for (int i = 0; i < half_row; i++) {
            for (int j = 0; j < half_col; j++) {
                //one_point_rotate(matrix, n, i, j);
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
