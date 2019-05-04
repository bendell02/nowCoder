class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> dp(n, INT_MAX);
        dp[0] = A[0];

        int maxSum = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = std::max(A[i], dp[i - 1] + A[i]);
            maxSum = std::max(maxSum, dp[i]);
        }

        return maxSum;
    }
};
