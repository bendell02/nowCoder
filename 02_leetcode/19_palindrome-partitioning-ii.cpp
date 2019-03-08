class Solution {
public:
    int minCut(string s) {
        int length = s.length();
 
        // dynamic program
        vector<vector<int> > flags(length + 1, vector<int>());
        vector<int> min_cut(length + 1, INT_MAX);
        flags[0].push_back(0);
        min_cut[0] = 0;
        for (int i = 1; i <= length; i++) {
            for (int j = 0; j<i; j++) {
                if (!flags.empty() && (isPalindrome(s.substr(j, i - j)))) {
                    flags[i].push_back(j);
                    min_cut[i] = std::min(min_cut[i], min_cut[j] + 1);
                }
            }
        }
 
        return (min_cut[length]-1);
    }
 
    bool isPalindrome(const string s) {
 
        int length = s.length();
        if (length <= 1) {
            return true;
        }
 
        int front_index = 0, back_index = length - 1;
        while (front_index < back_index) {
            if (s[front_index] != s[back_index]) {
                return false;
            }
            front_index++;
            back_index--;
        }
 
        return true;
    }
};