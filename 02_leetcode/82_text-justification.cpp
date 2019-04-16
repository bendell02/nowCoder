class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> result;
        int nums = words.size();
        vector<string> group;
        int currentLen = 0;
        for (int i = 0; i < nums; ++i) {
            int len_one_more = currentLen+words[i].length();
            len_one_more = (0 == currentLen) ? (len_one_more) : (len_one_more + 1);
            if (len_one_more > L) {
                solveOneGroup(group, result, currentLen, L);
                group.clear();
                currentLen = 0;
            }
            currentLen += words[i].length() + (group.empty() ? 0 : 1);
            group.push_back(words[i]);
        }
        solveLastGroup(group, result, L);
 
        return result;
    }
 
    void solveOneGroup(vector<string> &group, vector<string> &result, int &len, int &maxWidth) {
        string currentStr = "";
        if (1 == group.size()) {
            currentStr = group[0];
            currentStr += generateSpace(maxWidth - group[0].length());
        }
        else {
            int nums = group.size()-1;
            int numOfSpace = (maxWidth - len)/nums;
            int remainSpace = maxWidth - len - numOfSpace*nums;
            nums++;
            currentStr += group[0];
            for (int i = 1; i < nums; ++i) {
                if (remainSpace>0) {
                    currentStr += generateSpace(numOfSpace + 2) + group[i];
                }
                else {
                    currentStr += generateSpace(numOfSpace + 1) + group[i];
                }
                remainSpace--;
            }
        }
 
        result.push_back(currentStr);
    }
 
    void solveLastGroup(vector<string> &group, vector<string> &result, int &maxWidth) {
        string currentStr = "";
 
        int nums = group.size();
        for (int i = 0; i < nums; ++i) {
            if ("" == currentStr) { currentStr = group[i]; }
            else { currentStr += " " + group[i]; }
        }
        currentStr += generateSpace(maxWidth - currentStr.length());
 
        result.push_back(currentStr);
    }
 
    string generateSpace(int n) {
        string result = "";
        for (int i = 0; i < n; ++i) {
            result += " ";
        }
 
        return result;
    }
};
