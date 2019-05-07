class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (0 == strs.size()) { return res; }
 
        unordered_map<string, vector<string> > m;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
 
        for (unordered_map<string, vector<string> >::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
        }
 
        return res;
    }
};
