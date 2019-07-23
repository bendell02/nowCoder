#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long N, preMax, maxValue, temp;
    while(cin >> N) {
        cin >> maxValue;
        preMax = maxValue;
        for(int i=1; i<N; i++) {
            cin >> temp;
            preMax = max(temp, temp+preMax);
            if(maxValue < preMax) {
                maxValue = preMax;
            }
        }
        cout << maxValue << endl;
    }
    return 0;
}
