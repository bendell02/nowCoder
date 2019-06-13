class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rlt;
        dfs(n, n, "", rlt);
 
        return rlt;
    }
 
    void dfs(int left, int right, string tempRlt, vector<string> &rlt) {
        if (left > right) { return; }
 
        if (0 == left && 0 == right) {
            rlt.push_back(tempRlt);
            return;
        }
 
        if (left > 0) { dfs(left - 1, right, tempRlt + '(', rlt); }
        if (right > 0) { dfs(left, right - 1, tempRlt + ')', rlt); }
    }
};
