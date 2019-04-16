class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int nums = digits.size();
        for (int i=nums-1; i>=0; --i) {
            int temp = digits[i]+1;
            if (temp < 10) {
                digits[i] = temp;
                break;
            }
            else {
                digits[i] = 0;
                if (0 == i) {
                    digits.insert(digits.begin(), 1);
                }
            }
        }
         
        return digits;
    }
};
