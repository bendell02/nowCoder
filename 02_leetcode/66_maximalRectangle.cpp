class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // boundary
		if (matrix.empty()) { return 0; }

		// init variables
		const int rows = matrix.size();
		const int cols = matrix[0].size();
		vector<int> left(cols, 0), right(cols, cols);
		vector<int> height(cols, 0);

		// dp
		int cur_left = 0, cur_right = 0;
		int max_area = 0;
		for (int i = 0; i < rows; i++) {
			cur_left = 0; cur_right = cols;

			// update right
			for (int j = cols - 1; j >= 0; j--) {
				if ('1' == matrix[i][j]) { right[j] = std::min(right[j], cur_right); }
				else { right[j] = cols; cur_right = j; }
			}

			// update height ,left, maxArea
			for (int j = 0; j < cols; j++) {
				if ('1' == matrix[i][j]) { 
					height[j]++; 
					left[j] = std::max(left[j], cur_left);
				}
				else { 
					height[j] = 0; 
					left[j] = 0; cur_left = j + 1;
				}
				max_area = std::max(max_area, height[j] * (right[j] - left[j]));
			}
		}

		return max_area;
    }
};
