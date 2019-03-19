class Solution {
public:
    int numDistinct(string S, string T) {
        int length_s = S.length();
        int length_t = T.length();
        vector<vector<long long> > dp(length_t + 1, vector<long long>(length_s + 1, 0));
        for (int j = 0; j <= length_s; j++) {
            dp[0][j] = 1;
        }
 
        // dp
        for (int i = 1; i <= length_t; i++) {
            for (int j = 1; j <= length_s; j++) {
                dp[i][j] = dp[i][j - 1] + ((T[i - 1] == S[j - 1]) ? dp[i - 1][j - 1] : 0);
            }
        }
 
        return dp[length_t][length_s];
    }
};
