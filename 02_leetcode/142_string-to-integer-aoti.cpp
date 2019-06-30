class Solution {
public:
    int atoi(const char *str) {
        string str_(str);
        str_ = trim(str_);
        if (str_.empty()) { return 0; }
 
        int rltNumber = 0;
        bool isMinus = false;
        int len = str_.length();
        int index = 0;
 
        // sign
        if ('+' == str_[0]) {
            ++index;
        }
        else if ('-' == str_[0]) {
            isMinus = true;
            ++index;
        }
 
        for (; index < len; ++index) {
            if (str_[index]<'0' || str_[index]>'9') {
                break;
            }
 
            int bitNum = int(str_[index] - '0');
            long long tempNum = 10 * (long long)rltNumber + bitNum;
            if (tempNum > INT_MAX) {
 
                if (isMinus) { return INT_MIN; }
 
                rltNumber = INT_MAX;
                break;
            }
            rltNumber = 10 * rltNumber + bitNum;
        }
 
        if (isMinus) {
            rltNumber = 0 - rltNumber;
        }
 
        return rltNumber;
    }
 
    string& trim(string &s)
    {
        if (s.empty())
        {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
};
