class Solution {
public:
    string multiply(string num1, string num2) {
        if ("0" == num1 || "0" == num2) { return "0"; }
 
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 < len2) {
            swap(num1, num2);
            swap(len1, len2);
        }
 
        // one digit multiply
        vector<string> midStrings(len2);
        for (int i = len2 - 1; i >= 0; --i) {
            midStrings[i] = oneDigitMultiply(num1, num2[i])+string(len2-i-1, '0');
        }
 
        // sum
        string result = "";
        for (int i = 0; i < len2; ++i) {
            result = stringAdd(result, midStrings[i]);
        }
 
        return result;
    }
 
    string oneDigitMultiply(string num1, char ch) {
        string result;
        int len = num1.length();
        int carry = 0; char lastchar;
        for (int i = len - 1; i >= 0; i--) {
            charMultply(num1[i], ch, carry, lastchar);
            result = lastchar + result;
        }
 
        if (carry > 0) {
            result = char('0' + carry) + result;
        }
         
        return result;
    }
 
    void charMultply(char &ch1, char &ch2, int &carry, char &lastchar) {
        int result = int(ch1 - '0')*int(ch2 - '0');
        result += carry;
        carry = result / 10;
        result = result % 10;
        lastchar = '0' + result;
    }
 
    string stringAdd(string &s1, string &s2) {
        string result = "";
        int len1 = s1.length();
        int len2 = s2.length();
        int carry = 0; char lastchar; char zeroChar = '0';
 
        int index1 = len1 - 1;
        int index2 = len2 - 1;
 
        while (index1 >= 0 && index2 >= 0) {
            charAdd(s1[index1--], s2[index2--], carry, lastchar);
            result = lastchar + result;
        }
        while (index1 >= 0) {
            charAdd(s1[index1--], zeroChar, carry, lastchar);
            result = lastchar + result;
        }
        while (index2 >= 0) {
            charAdd(zeroChar, s2[index2--], carry, lastchar);
            result = lastchar + result;
        }
        if (carry > 0) {
            result = char('0' + carry) + result;
        }
 
        return result;
    }
 
    void charAdd(char &ch1, char &ch2, int &carry, char &lastchar) {
        int result = int(ch1 - '0') + int(ch2 - '0') + carry;
        carry = result / 10;
        result = result % 10;
        lastchar = '0' + result;
    }
};
