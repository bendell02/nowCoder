class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n-1;
        int mid = 0;
         
        if (target <= A[0]) {
            return 0;
        }
         
        while(left < right) {
            mid = (left + right) / 2;
             
            if (A[mid] < target) {
                left = mid+1;
            }
            else if (A[mid] == target) {
                return mid;
            }
            else {
                right = mid-1;
            }
        }
         
        if(A[left] >= target) {
            return left;
        }
        else {
            return left+1;
        }
    }
};
