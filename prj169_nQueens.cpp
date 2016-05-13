#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

// 得到n皇后的解及其个数，分别是iterative和recursive两种方法

string getString(const vector<int> &p)
{
    string rlt=""; int n = p.size();
    for(int i=0; i<n; i++) {
        rlt += ('0'+p[i]);
    }
    return rlt;
}

bool isValid(const vector<int> &p, int k)
{
    for(int i=0; i<k; i++) {
        if(abs(p[i]-p[k])==abs(i-k) || p[i]==p[k]) {
            return false;
        }
    }
    return true;
}

void isolve(vector<int> &p, vector<string> &rlt)
{
    int k=0, n=p.size();
    p[k]=0;
    while(k>=0) {
        p[k]++;
        while(p[k]<=n && !isValid(p, k)) {
            p[k]++;
        }
        if(p[k]<=n && k==n-1) {
            rlt.push_back(getString(p));
        } else {
            p[k]>n ? k-- : p[++k]=0;
        }
    }
}

int main()
{
    int N, idx;
    vector<int> p(8, 0); vector<string> rlt;
    isolve(p, rlt);
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> idx;
            cout << rlt[idx-1] << endl;
        }
    }
    return 0;
}
