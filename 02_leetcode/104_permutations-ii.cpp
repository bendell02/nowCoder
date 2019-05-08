class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        int len = num.size();
        if (0 == len) { return{}; }
 
        vector<bool> isVisited(len, false);
        vector<vector<int> > result;
        vector<int> temp;
        sort(num.begin(), num.end());
        dfs(0, len, temp, result, isVisited, num);
 
        return result;
    }
 
 
    void dfs(int index, int &len, vector<int> &temp, vector<vector<int> > &result, vector<bool> &isVisited, vector<int> &nums) {
        if (len == temp.size()) {
            result.push_back(temp);
            return;
        }
 
        for (int i = 0; i < len; ++i) {
            if (isVisited[i]) { continue; }
            if (i > 0 && nums[i] == nums[i - 1] && isVisited[i - 1] == false) { continue; }
 
            isVisited[i] = true;
            temp.push_back(nums[i]);
            dfs(i, len, temp, result, isVisited, nums);
            temp.pop_back();
            isVisited[i] = false;
        }
    }
};
