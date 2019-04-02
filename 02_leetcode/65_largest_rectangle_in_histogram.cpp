class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int i = 0;
        int length = height.size();
        stack<int> s_index;
        int max_area = 0, cur = 0, temp_area = 0;
        while (i < length) {
            if (s_index.empty() || (height[s_index.top()] <= height[i])) {
                s_index.push(i++);
            }
            else {
                cur = s_index.top(); s_index.pop();
                temp_area = height[cur]*(s_index.empty() ? i : (i - s_index.top() - 1));
                max_area = std::max(max_area, temp_area);
            }
        }
 
        return max_area;
    }
};
