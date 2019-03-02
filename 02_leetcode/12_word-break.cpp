class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int length = s.length();
 
        // dynamic program
        vector<bool> flags(length + 1, false);    // flags[i] means the word of substr(0, i) is breakable
        flags[0] = true;                        // "" is breakable
 
        string sub_str = "";
        for (int i = 0; i < length; i++) {
            sub_str = s.substr(0, i + 1);
            for (int j = 0; j <= i; j++) {
                if ((true == flags[j]) && (dict.count(sub_str.substr(j))>0)) {
                    flags[i + 1] = true;
                    break;
                }
            }
        }
 
        return flags[length];
    }
};