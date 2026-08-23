class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base cases: only 1 path along top row and left column
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        // Fill DP table bottom-up
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];   
    }
};
