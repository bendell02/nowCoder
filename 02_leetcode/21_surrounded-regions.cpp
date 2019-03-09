struct PointMy {
    int u;
    int v;
    PointMy() {}
    PointMy(int uu, int vv) {
        u = uu;
        v = vv;
    }
};
 
struct Board {
    int width;
    int height;
    Board(int wwidth, int hheight) {
        width = wwidth;
        height = hheight;
    }
 
    bool isValid(int u, int v) {
        if (u < 0 || u >= height || v < 0 || v >= width) {
            return false;
        }
 
        return true;
    }
};
 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (height <= 0) return;
        int width = board[0].size();
 
        vector<vector<bool> > isVisited(height, vector<bool>(width, false));
        vector<vector<bool> > o_region(height, vector<bool>(width, false));
        queue<PointMy> o_points;
 
        // get initial o_region. Solve the boundary.
        for (int i = 0; i < height; i++) {
            if ('O' == board[i][0]) {
                o_region[i][0] = true;
                isVisited[i][0] = true;
                o_points.push(PointMy(i, 0));
            }
            if ('O' == board[i][width - 1]) {
                o_region[i][width - 1] = true;
                isVisited[i][width - 1] = true;
                o_points.push(PointMy(i, width - 1));
            }
        }
        for (int j = 0; j < width; j++) {
            if ('O' == board[0][j]) {
                o_region[0][j] = true;
                isVisited[0][j] = true;
                o_points.push(PointMy(0, j));
            }
            if ('O' == board[height - 1][j]) {
                o_region[height - 1][j] = true;
                isVisited[height - 1][j] = true;
                o_points.push(PointMy(height - 1, j));
            }
        }
 
        // Solve the inner points
        PointMy current_point;
        Board b(width, height);
        int v_var[] = { -1, 0, 1, 0 };
        int u_var[] = { 0, -1, 0, 1 };
        int u_new = 0, v_new = 0;
        while (!o_points.empty()) {
            current_point = o_points.front(); o_points.pop();
            for (int i = 0; i < 4; i++) {
                u_new = current_point.u + u_var[i];
                v_new = current_point.v + v_var[i];
                if (b.isValid(u_new, v_new) && ('O'==board[u_new][v_new]) && (false == isVisited[u_new][v_new])) {
                    o_region[u_new][v_new] = true;
                    isVisited[u_new][v_new] = true;
                    o_points.push(PointMy(u_new, v_new));
                }
            }
        }
 
        // construct the result
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (o_region[i][j]) {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
