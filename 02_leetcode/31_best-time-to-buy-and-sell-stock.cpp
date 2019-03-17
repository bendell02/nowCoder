class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        if (length <= 1) {
            return 0;
        }
 
        vector<vector<int> > dp(length, vector<int>(2, 0));
        // dp[x][0]: lowest prices from day 0 to day x
        // dp[x][1]: maximum profit from day 0 to day x
        dp[0][0] = prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < length; i++) {
            dp[i][1] = std::max(dp[i - 1][1], prices[i] - dp[i - 1][0]);
            dp[i][0] = std::min(dp[i - 1][0], prices[i]);
        }
 
        return dp[length-1][1];
    }
};
