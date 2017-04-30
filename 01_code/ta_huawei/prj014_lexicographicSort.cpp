#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int N = 0; cin >> N;
    vector<string> strList(N);
    for(int i=0; i<N; i++) {
        cin >> strList[i];
    }

    // sort and output
    sort(strList.begin(), strList.end());
    for(int i=0; i<N; i++) {
        cout << strList[i] << endl;
    }
    return 0;
}
