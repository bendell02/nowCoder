class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<string> one_result;
		vector<vector<string> > result;
		dfs(result, one_result, s);
		return result;
    }

    void dfs(vector<vector<string> > &result, vector<string> &one_result, string s) {
        if ("" == s) {
            result.push_back(one_result);
        }

        for(int i=1; i<=s.length(); i++) {
            string sub = s.substr(0, i);
            if (isPalindrome(sub)) {
                one_result.push_back(sub);
                dfs(result, one_result, s.substr(i));
                one_result.pop_back();
            }
        }
    }

    bool isPalindrome(const string s) {
        int length = s.length();
        if (length <= 1) {
            return true;
        }

        int front_index = 0, back_index = length-1;
        while(front_index < back_index) {
            if (s[front_index] != s[back_index]) {
                return false;
            }
            front_index++;
            back_index--;
        }

        return true;
    }
};