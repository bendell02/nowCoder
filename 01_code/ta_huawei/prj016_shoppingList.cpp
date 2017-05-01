// reference website : http://blog.csdn.net/liang5630/article/details/8030108

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // data input
    int totalMoney=0, totalNum=0;
    cin >> totalMoney >> totalNum;
    vector<vector<int> > price(totalNum+1, vector<int>(3, 0));
    vector<vector<int> > weightedSum(totalNum+1, vector<int>(3, 0));
    int tempPrice, tempWeight, accessory;
    for(int i=1; i<=totalNum; i++) {
        cin >> tempPrice >> tempWeight >> accessory;
        if(0 == accessory) {
            price[i][0] = tempPrice;
            weightedSum[i][0] = tempPrice*tempWeight;
        } else {
            if(0 == price[accessory][1]) {
                price[accessory][1] = tempPrice;
                weightedSum[accessory][1] = tempPrice*tempWeight;
            } else {
                price[accessory][2] = tempPrice;
                weightedSum[accessory][2] = tempPrice*tempWeight;
            }
        }
    }

    // dynamic program
    vector<vector<int> > dp(totalNum+1, vector<int>(totalMoney+1, 0));
    for(int i=1; i<=totalNum; i++) {
        for(int j=1; j<=totalMoney; j++) {
            if(j>=price[i][0]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i][0]]+weightedSum[i][0]);
            }
            if(price[i][1] && j>=(price[i][0] + price[i][1])) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i][0]-price[i][1]]+weightedSum[i][0]+weightedSum[i][1]);
            }
            if(price[i][2] && j>=(price[i][0] + price[i][2])) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i][0]-price[i][2]]+weightedSum[i][0]+weightedSum[i][2]);
            }
            if(price[i][2] && j>=(price[i][0] + price[i][1] + price[i][2])) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i][0]-price[i][1]-price[i][2]]+weightedSum[i][0]+weightedSum[i][1]+weightedSum[i][2]);
            }
        }
    }

    cout << dp[totalNum][totalMoney] << endl;

    return 0;
}
