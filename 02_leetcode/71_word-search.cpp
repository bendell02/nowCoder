class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		// boundary
		if (board.empty()) {
			if ("" == word) { return true; }
			else { return false; }
		}
		if ("" == word) { return true; }

		rows = board.size();
		cols = board[0].size();
		len = word.length();
		isVisited.resize(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] == word[0]) {
					isVisited[i][j] = true;
					if (true == search(i, j, 1, board, word)) { return true; }
					isVisited[i][j] = false;
				}
			}
		}

		return false;
	}

	bool search(int row, int col, int index_char, vector<vector<char>>& board, string &word) {
		if (index_char == len) { return true; }

		for (int i = 0; i < 4; ++i) {
			int row_new = row + direction[i][0];
			int col_new = col + direction[i][1];
			if (isValid(row_new, col_new) && board[row_new][col_new] == word[index_char]) {
				isVisited[row_new][col_new] = true;
				if (true == search(row_new, col_new, index_char + 1, board, word)) {
					return true;
				}
				isVisited[row_new][col_new] = false;
			}
		}

		return false;
	}

	bool isValid(int &row, int &col) {
		if (row >= 0 && row < rows && col >= 0 && col < cols && (false == isVisited[row][col])) { return true; }
		else { return false; }
	}

private:
	int rows;
	int cols;
	int len;
	int direction[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
	vector<vector<bool> > isVisited;
}
