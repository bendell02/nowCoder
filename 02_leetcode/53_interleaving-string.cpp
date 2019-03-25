class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // check length
        int lengh1 = s1.length();
        int lengh2 = s2.length();
        if ((lengh1 + lengh2) != s3.length()) {
            return false;
        }
 
        // dp. dp[i][j] == true means s1[0..i-1] and s2[0..j-1] can construct s3[0..i+j-1]
        vector<vector<bool> > dp(lengh1 + 1, vector<bool>(lengh2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= lengh1; i++) {
            if ((s1[i - 1] == s3[i - 1]) && (true == dp[i - 1][0])) {
                dp[i][0] = true;
            }
        }
        for (int j = 1; j <= lengh2; j++) {
            if ((s2[j - 1] == s3[j - 1]) && (true == dp[0][j - 1])) {
                dp[0][j] = true;
            }
        }
 
        for (int i = 1; i <= lengh1; i++) {
            for (int j = 1; j <= lengh2; j++) {
                if ((s1[i - 1] == s3[i + j - 1]) && (true == dp[i - 1][j])) {
                    dp[i][j] = true;
                }
                if ((s2[j - 1] == s3[i + j - 1]) && (true == dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
 
        return dp[lengh1][lengh2];
    }
};
