#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        // If the total lengths do not match, it's impossible
        if (m + n != s3.length()) {
            return false;
        }

        // dp[i][j] = true if s1[0...i-1] and s2[0...j-1] form s3[0...i+j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty strings match empty s3
        dp[0][0] = true;

        // Base case 1: First column (using only s1)
        for (int i = 1; i <= m; i++) {
            if (dp[i - 1][0] == true) {
                if (s1[i - 1] == s3[i - 1]) {
                    dp[i][0] = true;
                }
            }
        }

        // Base case 2: First row (using only s2)
        for (int j = 1; j <= n; j++) {
            if (dp[0][j - 1] == true) {
                if (s2[j - 1] == s3[j - 1]) {
                    dp[0][j] = true;
                }
            }
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                // Choice 1: Can we match the current character of s3 from s1?
                if (dp[i - 1][j] == true) {
                    if (s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] = true;
                    }
                }

                // Choice 2: Can we match the current character of s3 from s2?
                if (dp[i][j - 1] == true) {
                    if (s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[m][n];
    }
};
