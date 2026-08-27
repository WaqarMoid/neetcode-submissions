class Solution {
public:
    int numDistinct(string s, string t) {

    int m = s.length();
        int n = t.length();

        // If s is shorter than t, it's impossible to form t
        if (m < n) return 0;

        // dp[i][j] stores number of distinct subsequences of s[0...i-1] equal to t[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base Case: An empty target t can be formed in 1 way from any prefix of s
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill table bottom-up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // Match: Use current char + Skip current char
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // Mismatch: Skip current char in s
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
    
};
