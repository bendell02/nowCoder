class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // boundary 
        if (n <= 0) { return 0; }
 
        int last_val = A[0];
        int freq = 0;
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == last_val) {
                freq++;
            }
            else {
                last_val = A[i];
                freq = 1;
            }
 
            if (freq <= 2) {
                A[index++] = A[i];
            }
        }
 
        return index;
    }
};
