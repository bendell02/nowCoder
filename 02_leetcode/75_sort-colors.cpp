class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0, right = n - 1;
        for (int i = 0; i <= right; ++i) {
          if (A[i] == 0) {
            swap(A[i], A[left++]);
          }
          else if(A[i] == 2) {
            swap(A[i--], A[right--]);
          }
        }
    }
};
