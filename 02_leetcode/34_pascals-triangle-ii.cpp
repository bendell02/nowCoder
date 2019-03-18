class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previous_row;
        vector<int> current_row;
 
        previous_row.resize(1, 1);
        current_row.resize(1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            current_row.resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                current_row[j] = previous_row[j - 1] + previous_row[j];
            }
            previous_row = current_row;
        }
 
        return current_row;
    }
};
