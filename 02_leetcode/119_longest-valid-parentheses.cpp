class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> s_p;
        for(int i=0;  i<s.length(); ++i) {
            if ('(' == s[i]) {
                s_p.push(i);
            }
            else if (')' == s[i]) {
                if (s_p.empty()) { start = i+1;}
                else {
                    s_p.pop();
                    res = (s_p.empty()) ? max(res, i-start+1) : max(res, i-s_p.top());
                }
            }
        }
        
        return res;
    }
};
