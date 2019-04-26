
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        //int len = s.length();
        if (len == 0) { return 0; }

        int result = 0;
        while ((--len)>=0) {
            if (' ' == s[len]) { 
                if (0 == result) { continue; }
                break; 
            }

            result++;
        }

        return result;
    }
};
