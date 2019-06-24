class Solution {
public:
    Solution() {
        genarateMap();
    }
 
    int romanToInt(string s) {
        int rltInteger = 0;
        int len = s.length();
        bool carryBit = false;
  
        for (int i = 0; i < len; ++i) {
            if ((i<len-1) && ('I' == s[i] || 'X' == s[i] || 'C' == s[i])) {
                rltInteger += solveDoubleChar(s[i], s[i + 1], carryBit);
                if (carryBit) { ++i; }
            }
            else {
                rltInteger += m[s[i]];
            }
        }
 
        return rltInteger;
    }
 
private:
    void genarateMap() {
        m['I'] = 1;     m['V'] = 5;
        m['X'] = 10;    m['L'] = 50;
        m['C'] = 100;   m['D'] = 500;
        m['M'] = 1000; 
 
        /*
        m['IV'] = 4;    m['IX'] = 9;   
        m['XL'] = 40;   m['XC'] = 90;  
        m['CD'] = 400;  m['CM'] = 900;
        */
    }
 
    int solveDoubleChar(char c1, char c2, bool &carryBit) {
        carryBit = true;
        if ('I' == c1) {
            if ('V' == c2)      { return 4; }
            else if ('X' == c2) { return 9; }
            else {
                carryBit = false;
                return 1;
            }
        }
        else if ('X' == c1) {
            if ('L' == c2)      { return 40; }
            else if ('C' == c2) { return 90; }
            else {
                carryBit = false;
                return 10;
            }
        }
        else if ('C' == c1) {
            if ('D' == c2)      { return 400; }
            else if ('M' == c2) { return 900; }
            else {
                carryBit = false;
                return 100;
            }
        }
         
        return 0;
    }
 
    map<char, int> m;
};
