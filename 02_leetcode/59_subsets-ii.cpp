class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
        // sort
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> out;
        helper(S, 0, out, result);
 
        return result;
    }
 
    void helper(vector<int> &nums, int pos, vector<int> &out, vector<vector<int> > &result) {
        result.push_back(out);
        for (int i = pos; i < nums.size(); i++) {
            out.push_back(nums[i]);
            helper(nums, i + 1, out, result);
            out.pop_back();
            while ((i + 1 < nums.size()) && (nums[i] == nums[i + 1])) i++;
        }
    }
};
