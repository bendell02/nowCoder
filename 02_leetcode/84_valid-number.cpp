class Solution {
public:
    bool isNumber(const char *s) {
        string ss(s);
        return isNumber(ss);
    }
     
    bool isNumber(string ss) {
        if (ss.empty()) { return false; }
 
        trim(ss);
 
        // judege '+' '-'
        if ('+' == ss[0] || '-' == ss[0]) { ss = ss.substr(1); }
 
        // judege 'e'
        std::size_t found = ss.find('e');
        if (found == std::string::npos) {
            return isDecimal(ss);
        }
        else {
            string basePart = ss.substr(0, found);
            string exponentPart = ss.substr(found + 1);
            if (exponentPart.empty()) { return false; }
            if ('+' == exponentPart[0] || '-' == exponentPart[0]) { exponentPart = exponentPart.substr(1); }
            return (isDecimal(basePart) && isInteger(exponentPart));
        }
    }
 
    bool isInteger(string &s) {
        if (s.empty()) { return false; }
 
        for (char c : s) {
            if (!(c >= '0' && c <= '9')) {
                return false;
            }
        }
 
        return true;
    }
 
    bool isDecimal(string &s) {
        std::size_t found = s.find('.');
        if (found == std::string::npos) {
            return isInteger(s);
        }
 
        string integerPart = s.substr(0, found);
        string decimalPart = s.substr(found + 1);
 
        if (integerPart.empty()) { return isInteger(decimalPart); }
        if (decimalPart.empty()) { return isInteger(integerPart); }
 
        return (isInteger(integerPart) && isInteger(decimalPart));
 
    }
 
    void trim(string &s) {
        if (s.empty()) { return; }
 
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
};
