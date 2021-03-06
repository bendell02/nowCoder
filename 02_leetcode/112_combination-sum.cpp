class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, out, res);
 
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
            dfs(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
