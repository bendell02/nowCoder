class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(num.begin(), num.end());
        dfs(num, target, 0, out, res);
        set<vector<int> > st(res.begin(), res.end());
        res.assign(st.begin(), st.end());
 
        return res;
    }
 
    void dfs(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) { return; }
 
        if (0 == target) {
            res.push_back(out);
            return;
        }
 
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1, out, res);
            out.pop_back();
        }
    }
};
