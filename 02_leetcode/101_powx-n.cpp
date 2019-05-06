class Solution {
public:
    double pow(double x, int n) {
        long long n_abs = std::llabs(n);
        double result = pow_core(x, n_abs);
        if (n < 0) {
            result = 1 / result;
        }
 
        return result;
    }
 
    double pow_core(double x, long long n_abs) {
        if (0 == n_abs) { return 1; }
        if (1 == n_abs) { return x; }
 
        double temp = pow_core(x, n_abs / 2);
        double result = temp*temp;
        if (1 == (n_abs & 0x1)) {
            result = result * x;
        }
 
        return result;
    }
};
