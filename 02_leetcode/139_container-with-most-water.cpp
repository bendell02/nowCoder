class Solution {
public:
    int maxArea(vector<int> &height) {
        int length = height.size();
        int maxWaters = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = i+1; j < length; ++j) {
                int w = j - i;
                int h = min(height[i], height[j]);
                int waters = w*h;
                if (waters > maxWaters) {
                    maxWaters = waters;
                }
            }
        }
 
        return maxWaters;
    }
};
