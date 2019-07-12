class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(2, 0);
        int len = numbers.size();

        for (int i = 0; i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if ((numbers[i] + numbers[j]) == target) {
                    res[0] = i+1;
                    res[1] = j+1;
                    return res;
                }
            }
        }

        return res;
    }
};
