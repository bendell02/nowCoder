class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        if (length <= 1) {
            return 0;
        }
 
        int max_profit = 0;
        for (int i = 1; i < length; i++) {
            if (prices[i] > prices[i - 1]) {
                max_profit += (prices[i] - prices[i - 1]);
            }
        }
 
        return max_profit;
    }
};
