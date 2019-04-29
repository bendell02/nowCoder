class Solution {
public:
    bool canJump(int A[], int n) {
        if (n < 1) { return true; }
 
        int max_dist = 0;
        for (int i = 0; i < n; ++i) {
            if (max_dist < i) { return false; }
            max_dist = std::max(i + A[i], max_dist);
            if (max_dist >= (n - 1)) { return true; }
        }
         
        return true;
    }
};
