class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int layers = triangle.size();
        if (layers <= 0) {
            return 0;
        }
 
        // dp
        vector<vector<int> > dp(layers, vector<int>());
        dp[0].push_back(triangle[0][0]);
        for (int i = 0; i < layers - 1; i++) {
            dp[i + 1].resize(i+1+1, INT_MAX);
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                dp[i + 1][j+1] = std::min(dp[i + 1][j+1], dp[i][j] + triangle[i + 1][j+1]);
            }
        }
 
        // find minimum
        int minimum = INT_MAX;
        for (int i = 0; i < layers; i++) {
            minimum = std::min(minimum, dp[layers - 1][i]);
        }
 
        return minimum;
    }
};
