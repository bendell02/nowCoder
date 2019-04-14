class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
 
        // init
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));
        for (int i = 0; i <= len1; ++i) { dp[i][0] = i; }
        for (int j = 0; j <= len2; ++j) { dp[0][j] = j; }
 
        // dp
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = std::min(dp[i][j-1] + 1, dp[i][j]);      // insertion
                dp[i][j] = std::min(dp[i-1][j] + 1, dp[i][j]);      // deletion
                if (word1[i - 1] == word2[j - 1]) {                 // replace
                    dp[i][j] = std::min(dp[i - 1][j - 1], dp[i][j]);
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
 
        return dp[len1][len2];
    }
};
