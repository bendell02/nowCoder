class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
         
        int bits = getBits(x);
        int base = pow(10, bits - 1);
        while (x) {
            int front = x / base;
            int rear = x % 10;
            if (front != rear) {
                return false;
            }
            x = x % base;
            x = x / 10;
            base /= 100;
        }
 
        return true;
    }
 
    int getBits(int x) {
        int b = 10;
        int bits = 1;
        while (x / b) {
            bits++;
            x /= b;
        }
 
        return bits;
    }
};
