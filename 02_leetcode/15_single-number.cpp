class Solution {
public:
    int singleNumber(int A[], int n) {
        if (1==n) return A[0];
 
        int rlt = A[0];
        for(int i=1; i<n; i++) {
            rlt ^= A[i];
        }
        return rlt;
    }
};
