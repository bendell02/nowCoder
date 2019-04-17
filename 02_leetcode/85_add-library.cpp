class Solution {
public:
    string addBinary(string a, string b) {
        int index1 = a.length()-1;
        int index2 = b.length()-1;
        string result = "";
        int carry = 0;
        int tempSum = 0;
        while (index1 >= 0 && index2 >= 0) {
            tempSum = ctoi(a[index1--]) + ctoi(b[index2--]) + carry;
            result = itoc(tempSum % 2) + result;
            carry = tempSum / 2;
        }
 
        while (index1 >= 0) {
            tempSum = ctoi(a[index1--]) + carry;
            result = itoc(tempSum % 2) + result;
            carry = tempSum / 2;
        }
 
        while (index2 >= 0) {
            tempSum = ctoi(b[index2--]) + carry;
            result = itoc(tempSum % 2) + result;
            carry = tempSum / 2;
        }
 
        if (carry > 0) { result = '1' + result; }
 
        return result;
    }
 
    int ctoi(char c) {
        return (c - '0');
    }
 
    char itoc(int i) {
        return ('0' + i);
    }
};
