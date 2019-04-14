class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
 
        string dir = "";
        vector<string> v;
        for (int i = 0; i < len; ++i) {
            if ('/' == path[i]) {
                if ("." == dir || "" == dir) {}
                else if (".." == dir) {
                    if (!v.empty()) {
                        v.pop_back();
                    }
                }
                else {
                    v.push_back(dir);
                }
                dir = "";
            }
            else { dir += path[i]; }
        }
        // last segment
        if ("." == dir || "" == dir) {}
        else if (".." == dir) {
            if (!v.empty()) {
                v.pop_back();
            }
        }
        else {
            v.push_back(dir);
        }
 
        // generate the result
        if (v.empty()) {
            return "/";
        }
        else {
            string result = "/";
            for (int i = 0; i < v.size()-1; ++i) {
                result = result + v[i] + "/";
            }
            result = result + v[v.size() - 1];
             
            return result;
        }
    }
};
