class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if (S.empty() || L.empty()) { return {}; }
         
        int len_s = S.length(), len = L[0].length();
        int n = L.size();
        vector<int> res;
        // calculate the map of words
        unordered_map<string, int> m1;
        for(string word:L) { ++m1[word]; }
         
        for(int i=0; i<=(len_s-len*n); ++i) {
            int j=0;
            unordered_map<string, int> m2;
            for(; j<n; ++j) {
                string word = S.substr(i+j*len, len);
                if (0 == m1.count(word)) { break; }
                ++m2[word];
                if (m2[word] > m1[word]) { break; }
            }
            if (j == n) {
                res.push_back(i);
            }
        }
         
        return res;
    }
};
