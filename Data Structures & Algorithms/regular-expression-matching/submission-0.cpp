class Solution {
public:
    bool isMatch(string s, string p) {
    int m = s.length();
        int n = p.length();

        // dp[i][j] represents if s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base Case 1: Empty string matches empty pattern
        dp[0][0] = true;

        // Base Case 2: Empty string matching patterns with '*' (e.g., "a*", "a*b*")
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill table bottom-up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    // Match single character or '.'
                    if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    // 1. Zero occurrence of preceding element (skip 2 columns back)
                    bool zeroMatch = dp[i][j - 2];

                    // 2. One or more occurrences (preceding char must match s[i-1])
                    bool oneOrMoreMatch = false;
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        oneOrMoreMatch = dp[i - 1][j];
                    }

                    dp[i][j] = zeroMatch || oneOrMoreMatch;
                }
            }
        }

        return dp[m][n];    
    }
};
