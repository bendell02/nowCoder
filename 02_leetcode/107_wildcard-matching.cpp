class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len_s = strlen(s);
        int len_p = strlen(p);
        vector<vector<bool> > dp(len_s + 1, vector<bool>(len_p + 1, false));
 
        // init dp
        dp[0][0] = true;
        for (int j = 1; j <= len_p; j++) {
            if ('*' == p[j - 1]) { dp[0][j] = true; }
            else { break; }
        }
 
        // dp
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_p; j++) {
                if ('*' == p[j - 1]) {
                    if (dp[i][j - 1] || dp[i - 1][j] || dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                else if ('?' == p[j - 1]) {
                    if (dp[i - 1][j - 1]) {
 
                        dp[i][j] = true;
                    }
                }
                else {
                    if (s[i - 1] == p[j - 1] && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
 
        return dp[len_s][len_p];
    }
};
