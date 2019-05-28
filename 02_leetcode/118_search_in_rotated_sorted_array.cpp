lass Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == A[mid]) { return mid; }
 
            if (A[mid] < A[right]) {
                if (A[mid] <= target && A[right] >= target) { left = mid + 1; }
                else { right = mid - 1; }
            }
            else {
                if (A[mid] >= target && A[left] <= target) { right = mid - 1; }
                else { left = mid + 1; }
            }
        }
 
        return -1;
    }
};
