class Solution {
public:
    // The solution is from https://leetcode.com/problems/word-break-ii/discuss/44386/My-concise-C%2B%2B-solution
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int length = s.length();
 
        // dynamic program
        vector<vector<int> > flags(length + 1, vector<int>());    // flags[i] means break point of the word of substr(0, i)
        flags[0].push_back(0);
        for (int i = 1; i <= length; i++) {
            for (int j = 0; j < i; j++) {
                if (!flags[j].empty() && dict.count(s.substr(j, i - j))>0) {
                    flags[i].push_back(j);
                }
            }
        }
 
        vector<string> rlt;
        generateResult(rlt, flags, s, s.size());
        reverse(rlt.begin(), rlt.end());
        return rlt;
    }
 
    void generateResult(vector<string> &result, vector<vector<int> > &flags, string s, int n) {
        for (int i : flags[n]) {
            if (0 == i) {
                result.push_back(s);
                continue;
            }
            s.insert(s.begin() + i, ' ');
            generateResult(result, flags, s, i);
            s.erase(i, 1);
        }
    }
};