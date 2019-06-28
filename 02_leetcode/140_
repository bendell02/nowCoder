class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len_s = strlen(s);
        int len_p = strlen(p);
        vector<vector<bool> > dp(len_p + 1, vector<bool>(len_s + 1, false));
 
        dp[0][0] = true;
        for (int i = 1; i <= len_p; ++i) {
            if (dp[i - 1][0] && (p[i - 1] == '*')) {
                dp[i][0] = true;
            }
            else if (p[i - 1] == '*' && (i > 1) && dp[i - 2][0]) {
                dp[i][0] = true;
            }
        }
 
        for (int i = 1; i <= len_p; ++i) {
            for (int j = 1; j <= len_s; ++j) {
                if (p[i - 1] == '*') {
                    if (dp[i - 1][j] || (i > 1 && dp[i - 2][j])) { dp[i][j] = true; }
                    if (dp[i][j - 1] && (i > 1 && (p[i - 2] == s[j - 1] || p[i - 2] == '.'))) { dp[i][j] = true; }
                }
                else if (p[i - 1] == '.') {
                    if (dp[i - 1][j - 1]) { dp[i][j] = true; }
                }
                else {
                    if (dp[i - 1][j - 1] && p[i - 1] == s[j - 1]) { dp[i][j] = true; }
                }
            }
        }
 
        return dp[len_p][len_s];
    }
};
