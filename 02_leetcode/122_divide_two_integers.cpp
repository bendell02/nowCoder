class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0==divisor || (INT_MIN==dividend && -1==divisor)) { return INT_MAX; }
         
        int sign = ((dividend<0)^(divisor<0)) ? -1 : 1;
        long long m = abs((long long) dividend);
        long long n = abs((long long) divisor);
        if (1 == n) {
            return (1==sign) ? m : -m;
        }
         
        int res = 0;
        while (m>=n) {
            long long t = n, p=1;
            while(m >= (t<<1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
         
        return (1==sign)? res : -res;
    }
};
