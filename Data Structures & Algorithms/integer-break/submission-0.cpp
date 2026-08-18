class Solution {
public:
    int integerBreak(int n) {
    // dp[i][j]: max product to make sum j using numbers from 1 to i
        // i ranges from 1 to n-1 (since we need at least k >= 2 pieces)
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: sum 0 has product multiplier 1
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                // Option 1: Don't use number i
                dp[i][j] = dp[i - 1][j];

                // Option 2: Use number i at least once (unbounded reuse on row i)
                if (j >= i) {
                    dp[i][j] = max(dp[i][j], dp[i][j - i] * i);
                }
            }
        }

        return dp[n - 1][n];   
    }
};