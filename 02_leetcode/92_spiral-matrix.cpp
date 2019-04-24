class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool> > flag(n, vector<bool>(n, false));
        int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        vector<vector<int> > result(n, vector<int>(n, 0));
        int temp = n*n;
        int x = 0, y = 0, k = 0;
        for (int i = 1; i <= temp; i++) {
            result[y][x] = i;
            flag[y][x] = true;
            for(int t=0; t<4; t++) {
                if (isValid(y + direction[k][1], x + direction[k][0], n, flag)) {
                    y = y + direction[k][1];
                    x = x + direction[k][0];
                    break;
                }
                k = (k + 1) % 4;
            }
        }

        return result;
    }

    bool isValid(int i, int j, int &n, vector <vector<bool> > &flag) {
        if (i < 0 || i>=n || j<0 || j >= n || (true == flag[i][j])) {
            return false;
        }


        return true;
    }
};
