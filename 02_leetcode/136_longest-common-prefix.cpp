class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefixCommon = "";
        int len = strs.size();
        if (1 == len) { return strs[0]; }
 
        int index = 0, i = 0;
        while (true) {
            for (i = 1; i < len; ++i) {
                if (strs[i].length() > index && strs[i - 1].length() > index && strs[i][index] == strs[i - 1][index]) {
                     
                }
                else {
                    break;
                }
            }
 
            if (i == len) {
                prefixCommon += strs[len-1][index];
                ++index;
            }
            else {
                break;
            }
        }
 
        return prefixCommon;
    }
};
