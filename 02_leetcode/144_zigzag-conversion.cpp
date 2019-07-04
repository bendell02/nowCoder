class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
 
        // numRows == 1
        if (1 == numRows) { return s; }
 
        // numRows >= 2
        int rows = calcRows(len, numRows);
        vector<vector<char> > zigzag(rows, vector<char>(numRows, ' '));
        int row = 0, col = 0;
        bool direction_horizontal = true;
        for (char c : s) {
            zigzag[row][col] = c;
 
            if (col == numRows - 1) {
                direction_horizontal = false;
            }
            else if (col == 0) {
                direction_horizontal = true;
            }
 
            if (direction_horizontal) {
                ++col;
            }
            else {
 
                ++row;
                --col;
            }
        }
 
        // generate result string
        string result = "";
        for (int j = 0; j < numRows; ++j) {
            for (int i = 0; i < rows; ++i) {
                if(zigzag[i][j] != ' ') {
                    result += zigzag[i][j];
                }
            }
        }
 
        return result;
    }
 
    int calcRows(int len, int n) {
        if (len <= n) { return 1; }
        int rows = 1;
 
        rows += (n - 1)*((len-n+2*n-1)/(2*n-2));
 
        return rows;
    }
};
