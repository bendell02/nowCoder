class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size();
        vector<vector<int> > res;
         
        sort(num.begin(), num.end());
         
        for(int i=0; i<len-3; ++i) {
            if (i>0 && (num[i] == num[i-1])) { continue; }
             
            for(int j=i+1; j<len-2; ++j) {
                if(j>i+1 && (num[j] == num[j-1])) { continue; }
                 
                int left = j+1, right=len-1;
                while(left < right) {
                    int sum = num[i]+num[j]+num[left]+num[right];
                    if (sum == target) {
                        vector<int> out{num[i], num[j], num[left], num[right]};
                        res.push_back(out);
                        while(left<right && num[left]==num[left+1]) { ++left; };
                        while(left<right && num[right] == num[right-1]) { --right; }
                         
                        ++left; --right;
                    }
                    else if (sum < target) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }
         
        return res;
    }
};
