class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        m--; n--;
        while ((m >= 0) && (n >= 0)) {
            if (A[m] > B[n]) {
                A[index--] = A[m--];
            }
            else {
                A[index--] = B[n--];
            }
        }
        if (n >= 0) {
            while (n >= 0) {
                A[index--] = B[n--];
            }
        }
    }
}
