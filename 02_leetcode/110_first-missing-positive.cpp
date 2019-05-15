class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        vector<bool> isVisited(n+2, false);
        for(int i=0; i<n; ++i) {
            if (A[i]>0 && A[i] <= n) {
                isVisited[A[i]] = true;
            }
        }
         
        int res = 0;
        for(int i=1; i<n+2; ++i) {
            if (false == isVisited[i]) {
                res = i;
                break;
            }
        }
         
        return res;
    }
};
