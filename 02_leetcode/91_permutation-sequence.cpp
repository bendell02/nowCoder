class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "123456789";
        
        // init f
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) { f[i] = f[i - 1] * i; }

        string result = "";
        --k; int j = 0;
        for (int i = n; i >= 1; --i) {
            j = k / f[i - 1];
            k = k % f[i - 1];
            result += nums[j];
            nums.erase(j, 1);
        }

        return result;
    }
};
