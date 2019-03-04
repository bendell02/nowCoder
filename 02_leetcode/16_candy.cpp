#include <numeric>
 
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> candies(length, 1);   // candies[i] means ith child has candies[i] candies.
        for (int i = 1; i < length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
 
            // check if it need updating data
            int j = i - 1;
            while (j >= 0) {
                if (ratings[j] <= ratings[j + 1]) {
 
                    break;
                }
                if ((ratings[j] > ratings[j + 1]) && (candies[j] > candies[j + 1])) {
                    break;
                }
 
                // should updata data
                candies[j] = candies[j + 1] + 1;
                j--;
            }
        }
 
        return (accumulate(candies.begin(), candies.end(), 0));
    }
};