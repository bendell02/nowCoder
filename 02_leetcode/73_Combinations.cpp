class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> path;
		dfs(n, k, 0, 1, path, result);

		return result;
	}

	void dfs(int &n, int &k, int count, int index, vector<int> &path, vector<vector<int> > &result) {
		if (count == k) {
			result.push_back(path);
			return;
		}

		for (int i = index; i <= n; i++) {
			path.push_back(i);
			dfs(n, k, count + 1, i + 1, path, result);
			path.pop_back();
		}
	}
};
