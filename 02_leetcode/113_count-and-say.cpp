class Solution {
public:
    string countAndSay(int n) {
        string num = "1";
        if (n <= 1) { return num; }
 
        string temp_num = "";
        int count = 0;
        while (--n) {
            temp_num = "";
            count = 1; 
            char lastChar = num[0];
            for (int i = 1; i < num.length(); ++i) {
                if (num[i] == num[i - 1]) {
                    ++count;
                }
                else {
                    temp_num = temp_num + std::to_string(count) + lastChar;
                    count = 1;
                    lastChar = num[i];
                }
            }
            temp_num = temp_num + std::to_string(count) + lastChar;
            num = temp_num;
        }
 
        return num;
    }
};
