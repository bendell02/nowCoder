class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) { return false; }
        if (0 == s1.compare(s2)) { return true; }
 
        // important. check if two string have same letters. No this will cause Timeout
        string str1 = s1; string str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (0 != str1.compare(str2)) { return false; }
 
        int length = s1.length();
        for (int i = 1; i < length; i++) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) { return true; }
 
            s21 = s2.substr(length - i);
            s22 = s2.substr(0, length - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) { return true; }
        }
 
        return false;
    }
};
