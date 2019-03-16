class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        if (length <= 1) {
            return 0;
        }
 
        int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
        for (int i = 0; i < length; i++) {
            buy1 = std::max(buy1, -prices[i]);              //left money after buy1
            sale1 = std::max(sale1, prices[i] + buy1);      //left money after sale1
            buy2 = std::max(buy2, sale1 - prices[i]);       //left money after buy2
            sale2 = std::max(sale2, prices[i] + buy2);      //left money after sale2
        }
 
        return sale2;
    }
};
