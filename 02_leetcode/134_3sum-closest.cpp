class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
         
        sort(num.begin(), num.end());
         
        int sum = 0, diff_min = INT_MAX, closest_value = 0;
        for(int i1=0; i1<len-2; ++i1) {
            if (i1>0 && (num[i1]==num[i1-1])) { continue; }
             
            for(int i2=i1+1; i2<len-1; ++i2) {
                if (i2 > i1+1 && (num[i2] == num[i2-1])) { continue; }
                 
                for(int i3=i2+1; i3<len; ++i3) {
                    if (i3 > i2+1 && (num[i3] == num[i3-1])) { continue; }
                     
                    sum = num[i1]+num[i2]+num[i3];
                    int diff = abs(sum - target);
                    if (diff == 0) {
                        return target;
                    }
                    else {
                        if (diff < diff_min) {
                            diff_min = diff;
                            closest_value = sum;
                        }
                    }
                }
            }
        }
         
        return closest_value;
    }
};
