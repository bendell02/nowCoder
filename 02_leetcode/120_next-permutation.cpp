class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        int i=len-2, j=len-1;
        
        while(i>=0 && (num[i+1]<=num[i])) { --i; }
        
        if (i>=0) {
            while(num[j]<=num[i]) { --j; }
            
            swap(num[i], num[j]);
        }
        
        reverse(num.begin()+i+1, num.end());
    }
};
