class Solution {
public:
    bool isValid(string s) {
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
 
        stack<char> bracket;
        for (char c : s) {
            if ('(' == c || '[' == c || '{' == c) {
                bracket.push(c);
            }
            else {
                if (false == isValid(m[c], bracket)) {
 
                    return false;
                }
            }
        }
         
        if (!bracket.empty()) { return false; }
 
        return true;
    }
 
    bool isValid(char c, stack<char> &bracket) {
        if (!bracket.empty() && bracket.top() == c) {
            bracket.pop();
        }
        else {
            return false;
        }
 
        return true;
    }
};
