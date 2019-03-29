class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (length <= 0 || ('0' == s[0])) return 0;
 
        int prev_2 = 1;
        int prev_1 = 1;
        int cur = 1;
        for (int i = 1; i < length; i++) {
            cur = ('0' == s[i]) ? 0 : prev_1;
            if (isValid(s.substr(i - 1, 2))) {
                cur += prev_2;
            }
            prev_2 = prev_1;
            prev_1 = cur;
        }
 
        return cur;
    }
 
    bool isValid(string str) {
        int num = std::stoi(str);
        if (num >= 10 && num <= 26) {
            return true;
        }
 
        return false;
    }
};
