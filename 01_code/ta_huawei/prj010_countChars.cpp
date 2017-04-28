#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<bool> isExist(128, false);
    cin >> str;
    int nums = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i]>=0 && str[i]<=127) {
            if(false == isExist[str[i]]) {
                nums++;
                isExist[str[i]] = true;
            }
        }
    }
    cout << nums << endl;

    return 0;
}
