class Solution {
public:
    int jump(int A[], int n) {
        int steps = 0, i = 0, cur = 0, last = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur = max(cur, i + A[i]);
            if (i == last) {
                last = cur;
                ++steps;
                if (cur >= n - 1) break;
            }
        }
 
        return steps;
    }
};
