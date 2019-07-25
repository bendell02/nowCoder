#include <iostream>
#include <limits.h>
#include <vector>
#define MAXN 600

using namespace std;

int N, M, minDist, diff;
vector<vector<pair<int, int> > > edges(MAXN);
vector<int> leaders(MAXN, 0);
vector<bool> visited(MAXN, false);

void dfs(int curr, int dist)
{
    if(dist >= minDist) return;
    if(curr == 1) {
        minDist = dist; return;
    }
    for(int j=0; j<edges[curr].size(); j++) {
        int i=edges[curr][j].first;
        int tempDist = edges[curr][j].second;
        if(!visited[i] && tempDist<INT_MAX) {
            if(leaders[curr] != leaders[i]) {
                diff++;
                if(diff>1) {
                    diff--; continue;
                }
            }
            visited[i] = true;
            dfs(i, dist+tempDist);
            visited[i] = false;
            if(leaders[curr] != leaders[i]) {
                diff--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N && N) {
        cin >> M; int c1, c2, t;
        for(int m=0; m<M; m++) {
            cin >> c1 >> c2 >> t;
            edges[c1-1].push_back(make_pair(c2-1, t));
            edges[c2-1].push_back(make_pair(c1-1, t));
        }
        for(int n=0; n<N; n++) {
            cin >> leaders[n];
        }
        minDist = INT_MAX; diff = 0; visited[0] = true;
        dfs(0, 0);
        if(minDist < INT_MAX) {
            cout << minDist << endl;
        } else {
            cout << "-1" << endl;
        }
        // ¸´Î»
        for(int i=0; i<N; i++) {
            visited[i] = false;
            edges[i].clear();
        }
    }
    return 0;
}
