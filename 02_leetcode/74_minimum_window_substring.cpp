class Solution {
public:
	string minWindow(string S, string T) {
		vector<int> frequency(128, 0);
		for (char c : T) { ++frequency[c]; }

		int len_s = S.length();
		int len_t = T.length();
		int count = 0, min_len = INT_MAX, left = 0;
		string result = "";
		for (int i = 0; i < len_s; ++i) {
			if (--frequency[S[i]] >= 0) { ++count; }
			while (count == len_t) {
				if (min_len > (i - left + 1)) {
					min_len = i - left + 1;
					result = S.substr(left, min_len);
				}

				if (++frequency[S[left]] > 0) { --count; }
				++left;
			}
		}

		return result;
	}
};
