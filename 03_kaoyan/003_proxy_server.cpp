#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<string> NList, MList;

int searchIdx(vector<string> &List, string &str, int &N)
{
    int left = 0, right = N-1, mid = right >> 1;
    while(left <= right) {
        if(List[mid] < str) {
            left = mid + 1;
        } else if(List[mid] > str) {
            right = mid - 1;
        } else {
            return mid;
        }
        mid = (left + right) >> 1;
    }
    return -1;
}

int countCoversion(int start)
{
    vector<bool> visited(N, false); int rlt = 0, idx, cnt=N;
    for(int i=start; i<M; i++) {
        if((idx = searchIdx(NList, MList[i], N)) >= 0) {
            if(!visited[idx]) {
                visited[idx] = true; cnt--;
            }
            if(cnt == 0) {
                rlt = 1 + countCoversion(i);
                break;
            }
        }
    }
    return rlt;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> N) {
        NList.resize(N);
        for(int i=0; i<N; i++) {
            cin >> NList[i];
        }
        cin >> M; MList.resize(M);
        for(int i=0; i<M; i++) {
            cin >> MList[i];
        }
        sort(NList.begin(), NList.end());
        if(N==1) {
            if(searchIdx(MList, NList[0], M)>=0) {
                cout << "-1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else {
            cout << countCoversion(0) << endl;
        }
    }
    return 0;
}
