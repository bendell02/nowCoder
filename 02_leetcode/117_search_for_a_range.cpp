class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res = { -1, -1 };
        if (n < 1) { return res; }
 
        int left = 0, right = n - 1;
        int mid = 0;
 
        if (target < A[0]) {
            return res;
        }
 
        while (left <= right) {
            mid = (left + right) / 2;
 
            if (A[mid] < target) {
                left = mid + 1;
            }
            else if (A[mid] == target) {
                break;
            }
            else {
                right = mid - 1;
            }
        }
 
        if (A[mid] == target) {
            res[0] = mid;
            res[1] = mid;
 
            while (res[0] - 1 >= 0 && target == A[res[0] - 1]) { --res[0]; }
            while (res[1] + 1 < n && target == A[res[1] + 1]) { ++res[1]; }
        }
 
        return res;
    }
};
