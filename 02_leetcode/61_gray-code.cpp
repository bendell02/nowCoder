class Solution {
public:
    vector<int> grayCode(int n) {
        // boundary
        vector<int> result;
        result.push_back(0);
        if (n <= 0) return result;
 
        // initial value
        result.push_back(1);
 
        // dp
        int cur_size = 0;
        int cur_base = 0;
        for (int i = 1; i < n; i++) {
            cur_base = 1 << i;
            cur_size = result.size();
            for (int j = cur_size - 1; j >= 0; j--) {
                result.push_back(cur_base + result[j]);
            }
        }
 
        return result;
    }
};
