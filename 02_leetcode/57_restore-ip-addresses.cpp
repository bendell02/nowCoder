class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int length = s.length();
        vector<string> result;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    for (int l = 1; l <= 3; l++) {
                        if ((i + j + k +l) == length) {
                            string str_i = s.substr(0, i);
                            string str_j = s.substr(i, j);
                            string str_k = s.substr(i + j, k);
                            string str_l = s.substr(i + j + k, l);
                            if (isValid(str_i) && isValid(str_j) && isValid(str_k) && isValid(str_l)) {
                                result.push_back(str_i + "." + str_j + "." + str_k + "." + str_l);
                            }
                        }
                    }
                }
            }
        }
 
        return result;
    }
 
    bool isValid(string &str) {
        if (str.length() > 1 && ('0' == str[0])) {
            return false;
        }
 
        int num = std::stoi(str);
        if (num >= 0 && num <= 255) {
            return true;
        }
 
        return false;
    }
};
