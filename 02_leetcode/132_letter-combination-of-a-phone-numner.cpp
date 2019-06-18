class Solution {
public:
    vector<string> letterCombinations(string digits) {        
        generateDict(dict);
        generatePhoneNumbers(digits);
        vector<string> strResult;
        dfs(0, "", strResult);
        
        return strResult;
    }
    
    void dfs(int index, string midResult, vector<string> &strResult) {
        if (index == len) {
            strResult.push_back(midResult);
            return;
        }
        int num = phoneNumbers[index];
        for(int i=0; i < dict[num].size(); ++i) {
            dfs(index+1, midResult+dict[num][i], strResult);
        }
    }
    
    void generateDict(vector<vector<char> > &dict) {
        dict.clear();
        
        vector<char> keyValues0, keyValues1;
        dict.push_back(keyValues0);
        dict.push_back(keyValues1);
        vector<char> keyValues2 = {'a', 'b', 'c'};
        vector<char> keyValues3 = {'d', 'e', 'f'};
        vector<char> keyValues4 = {'g', 'h', 'i'};
        vector<char> keyValues5 = {'j', 'k', 'l'};
        vector<char> keyValues6 = {'m', 'n', 'o'};
        vector<char> keyValues7 = {'p', 'q', 'r', 's'};
        vector<char> keyValues8 = {'t', 'u', 'v'};
        vector<char> keyValues9 = {'w', 'x', 'y', 'z'};
        dict.push_back(keyValues2);
        dict.push_back(keyValues3);
        dict.push_back(keyValues4);
        dict.push_back(keyValues5);
        dict.push_back(keyValues6);
        dict.push_back(keyValues7);
        dict.push_back(keyValues8);
        dict.push_back(keyValues9);
    }
    
    void generatePhoneNumbers(string digits) {
        len = digits.length();
        phoneNumbers.clear();
        
        for(char c : digits) {
            phoneNumbers.push_back(int(c-'0'));
        }
    }
    
private:
    vector<vector<char> >dict;
    vector<int> phoneNumbers;
    int len;
};
