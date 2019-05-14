class Solution {
public:
    int trap(int A[], int n) {
        stack<int> s;
        int i=0, res = 0;
        while(i<n) {
            if(s.empty() || A[i]<=A[s.top()]) {
                s.push(i++);
            }
            else {
                int t = s.top(); s.pop();
                if (s.empty()) { continue; }
                 
                res += (min(A[i], A[s.top()]) - A[t]) * (i-s.top()-1);
            }
        }
        return res;
    }
};
