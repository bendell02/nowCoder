class Solution {
public:
	bool isPalindrome(string s) {
		// transform to lower letter
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		// remove not-alphabetnumberic character
		int length = s.length();
		string s_naked;
		for (int i = 0; i < length; i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0') && s[i] <= '9') {
				s_naked.push_back(s[i]);
			}
		}

		// check if it is palindrome
		length = s_naked.length();
		if (length <= 1) {
			return true;
		}

		int front_index = 0, back_index = length - 1;
		while (front_index < back_index) {
			if (s_naked[front_index] != s_naked[back_index]) {
				return false;
			}
			front_index++;
			back_index--;
		}

		return true;
	}
};
