class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) { return 0; }
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<long int> > dp(rows, vector<long int>(cols, 0));
        if (1 == obstacleGrid[0][0]) { return 0; }
        if (1 == obstacleGrid[rows - 1][cols - 1]) { return 0; }
 
        dp[0][0] = 1;
        for (int i = 1; i < rows; ++i) {
            if (0 == obstacleGrid[i][0]) { dp[i][0] = 1; }
            else { break; }
        }
        for (int j = 1; j < cols; ++j) {
            if (0 == obstacleGrid[0][j]) { dp[0][j] = 1; }
            else { break;}
        }
 
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (1 == obstacleGrid[i][j]) { continue; }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
 
        return dp[rows - 1][cols - 1];
    }
};
