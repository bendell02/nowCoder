class Solution {
public:
    vector<vector<int>> subsets(vector<int>& S) {
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        int total = 1 << (S.size());
        for (int i = 0; i < total; i++) {
            convertInt2vector(S, i, result);
        }
 
        sort(result.begin(), result.end());
        vector<vector<int> > result_adjust;
        result_adjust.push_back(vector<int>());
        for (int j = 1;j <= S.size();j++) {
            for (int k = 0;k < result.size();k++) {
                if (result[k].size() == j)
                {
                    result_adjust.push_back(result[k]);
                }
            }
        }
        return result_adjust;
    }
 
    void convertInt2vector(vector<int> &nums, int num, vector<vector<int> > &result) {
        vector<int> sub;
        int index = 0;
        for (int i = num; i > 0; i >>= 1) {
            if ((i & 0x1) == 1) {
                sub.push_back(nums[index]);
            }
            index++;
        }
        result.push_back(sub);
    }
};
