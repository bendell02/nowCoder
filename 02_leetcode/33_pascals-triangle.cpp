class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tringle(numRows, vector<int>());
 
        for (int i = 0; i < numRows; i++) {
            tringle[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                tringle[i][j] = tringle[i - 1][j - 1] + tringle[i - 1][j];
            }
        }
 
        return tringle;
    }
};
