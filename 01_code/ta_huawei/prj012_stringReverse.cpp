#include <iostream>
#include <string>

using namespace std;

int main()
{
    string oriStr;
    cin >> oriStr;
    for(int i=oriStr.length()-1; i>=0; i--) {
        cout << oriStr[i];
    }
    cout << endl;
    return 0;
}
