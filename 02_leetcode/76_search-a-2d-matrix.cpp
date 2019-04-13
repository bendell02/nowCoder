class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) { return false; }
 
        int rows = matrix.size();
        int cols = matrix[0].size();
 
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) { return true; }
            else if (matrix[i][j] < target) { ++i; }
            else { --j; }
        }
 
        return false;
    }
};
