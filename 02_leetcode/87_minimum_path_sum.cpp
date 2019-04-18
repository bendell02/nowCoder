class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) { return 0; }
 
        int rows = grid.size();
        int cols = grid[0].size();
 
        vector<vector<int> > dp(rows, vector<int>(cols, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; ++i) { dp[i][0] = dp[i - 1][0] + grid[i][0]; }
        for (int j = 1; j < cols; ++j) { dp[0][j] = dp[0][j - 1] + grid[0][j]; }
 
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
 
        return dp[rows - 1][cols - 1];
    }
};
