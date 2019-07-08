class Solution {
public:
    string longestPalindrome(string s) {
        // insert #
        string t = "$#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        // process t
        vector<int> p(t.length(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.length(); ++i) {
            p[i] = (mx > i) ? min(p[2 * id - i],mx-i) : 1;
            while ((i-p[i]>=0) && t[i + p[i]] == t[i - p[i]]) {
                ++p[i];
            }
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }

        return s.substr((resCenter-resLen)/2, resLen - 1);
    }
};
