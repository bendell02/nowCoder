class Solution {
public:
    int singleNumber(int A[], int n) {
        int one_time = 0;
        int two_time = 0;
        int three_time = 0;
        for(int i=0; i<n; i++) {
            two_time |= (one_time&A[i]);
            one_time ^= A[i];
            three_time = one_time & two_time;
            one_time &= (~three_time);
            two_time &= (~three_time);
        }
 
        return one_time;
    }
};
