// 按照 牛客673854  的思路写得

#include <iostream>
#include <queue>

using namespace std;

const int chessSize = 6;
int sx, sy, ex, ey;
const int direction[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

class Point {
    public:
        int x, y, s;
        Point(int _x, int _y, int _s) {
            x = _x; y = _y; s = _s;
        }
};

int chess[chessSize][chessSize];
int cost[chessSize][chessSize][5];

void BFS()
{
    cost[sx][sy][1] = 0;
    queue<Point> q;
    q.push(Point(sx, sy, 1));
    while(!q.empty()) {
        Point now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = now.x + direction[i][0];
            int ny = now.y + direction[i][1];
            if(nx<0 || nx>=chessSize || ny<0 || ny>=chessSize) {
                continue;
            }
            int c = chess[nx][ny]*now.s;
            int s = (c%4) + 1;
            if(cost[nx][ny][s]==-1 || cost[nx][ny][s]>cost[now.x][now.y][now.s]+c) {
                q.push(Point(nx, ny, s));
                cost[nx][ny][s] = cost[now.x][now.y][now.s]+c;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for(int n=0; n<N; n++) {
        for(int i=0; i<chessSize; i++) {
            for(int j=0; j<chessSize; j++) {
                cin >> chess[i][j];
                for(int t=1; t<=4; t++) {
                    cost[i][j][t] = -1;
                }
            }
        }
        cin >> sx >> sy >> ex >> ey;
        BFS();
        int rlt = -1;
        for(int i=1; i<=4; i++) {
            if(cost[ex][ey][i] != -1) {
                if(rlt==-1 || rlt>cost[ex][ey][i]) {
                    rlt = cost[ex][ey][i];
                }
            }
        }
        cout << rlt << endl;
    }
    return 0;
}
