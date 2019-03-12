class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		vector<vector<string> > paths;
		if (dict.find(endWord) == dict.end()) {
			return paths;
		}

		graph g;
		vector<string> one_path = { beginWord };
		if (buildGraph(g, beginWord, endWord, dict)) {
			findPaths(g, beginWord, endWord, one_path, paths);
		}
		
		return paths;
	}

private:
	typedef unordered_map<string, vector<string> > graph;

	bool buildGraph(graph &g, string &beginWord, string &endWord, unordered_set<string> &dict) {
		unordered_set<string> todo;
		todo.insert(beginWord);
		while (!todo.empty()) {
			if (todo.find(endWord) != todo.end()) {
				return true;
			}

			// erase exist words
			for (string word : todo) {
				dict.erase(word);
			}

			// add children
			unordered_set<string> next;
			for (string word : todo) {
				string parent = word;
				for (int i = 0; i < word.length(); i++) {
					char c = word[i];
					for (int j = 0; j < 26; j++) {
						word[i] = 'a' + j;
						if (dict.find(word) != dict.end()) {
							next.insert(word);
							g[parent].push_back(word);
						}
					}
					word[i] = c;
				}
			}
			swap(todo, next);
		}
		
		return false;
	}

	void findPaths(graph &g, string beginWord, string endWord, vector<string> &one_path, vector<vector<string> > &paths) {
		if (beginWord == endWord) {
			paths.push_back(one_path);
		}
		else {
			for (string child : g[beginWord]) {
				one_path.push_back(child);
				findPaths(g, child, endWord, one_path, paths);
				one_path.pop_back();
			}
		}
	}
};
