class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) { return 0; }
 
        bool isMinus = false;
        if (x < 0) {
            isMinus = true;
            x = abs(x);
        }
 
        int rltNum = 0;
        while (x) {
            int tempNum = x % 10;
            long long tempSum = (long long)rltNum * 10 + tempNum;
 
            if (tempSum > INT_MAX) { return 0; }
 
            rltNum = rltNum * 10 + tempNum;
            x = x / 10;
        }
 
        if (isMinus) {
            rltNum = -rltNum;
        }
 
        return rltNum;
    }
};
