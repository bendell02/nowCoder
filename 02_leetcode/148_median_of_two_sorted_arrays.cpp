class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(A, m, 0, B, n, 0, left) + findKth(A, m, 0, B, n, 0, right)) / 2.0;
    }

    int findKth(int A[], int m, int i, int B[], int n, int j, int k) {
        if (i >= m) { return B[j + k - 1]; }
        if (j >= n) { return A[i + k - 1]; }
        if (1 == k) { return min(A[i], B[j]); }

        int midVal1 = (i + k / 2 - 1 < m) ? (A[i + k / 2 - 1]) : (INT_MAX);
        int midVal2 = (j + k / 2 - 1 < n) ? (B[j + k / 2 - 1]) : (INT_MAX);
        if (midVal1 < midVal2) {
            return findKth(A, m, i + k / 2, B, n, j, k - k / 2);
        }
        else {
            return findKth(A, m, i, B, n, j + k / 2, k - k / 2);
        }
    }
};
