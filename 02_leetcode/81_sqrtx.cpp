class Solution {
public:
    int sqrt(int x) {
        if (x <= 1) { return x; }
 
        int left = 0, right = x, mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (x / mid >= mid) { left = mid + 1; }
            else { right = mid; }
        }
         
        return (right - 1);
    }
};
