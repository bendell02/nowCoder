class Solution {
public:
    Solution() {
        generatePairVector();
        vectorLength = pairVector.size();
    }

    string intToRoman(int num) {
        string romanStr = "";
        for (int i = 0; i < vectorLength; ++i) {
            while (num / pairVector[i].first) {
                romanStr += pairVector[i].second;
                num -= pairVector[i].first;
            }
        }

        return romanStr;
    }

private:
    void generatePairVector() {
        pairVector.clear();
        pairVector.push_back(make_pair(1000, "M"));
        pairVector.push_back(make_pair(900, "CM"));
        pairVector.push_back(make_pair(500, "D"));
        pairVector.push_back(make_pair(400, "CD"));
        pairVector.push_back(make_pair(100, "C"));
        pairVector.push_back(make_pair(90, "XC"));
        pairVector.push_back(make_pair(50, "L"));
        pairVector.push_back(make_pair(40, "XL"));
        pairVector.push_back(make_pair(10, "X"));
        pairVector.push_back(make_pair(9, "IX"));
        pairVector.push_back(make_pair(5, "V"));
        pairVector.push_back(make_pair(4, "IV"));
        pairVector.push_back(make_pair(1, "I"));
    }
    vector<pair<int, string> >  pairVector;
    int                         vectorLength;
};
