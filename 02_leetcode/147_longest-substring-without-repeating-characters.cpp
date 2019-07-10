class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) { return 0; }

        int len = s.length();
        vector<int> dp(len, 1);
        int maxLen = 1;

        for (int i = 1; i < len; ++i) {
            int index = i-1;
            while (index >= (i - dp[i - 1])) {
                if (s[index] == s[i]) { break;}
                
                ++dp[i];
                --index;

            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
