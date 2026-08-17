class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        // dp[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // Traverse rows bottom-up, columns left-to-right
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    // Lengths 1, 2, or 3 (j - i <= 2) don't need inner checks:
                    // - len 1: "a" (j - i = 0)
                    // - len 2: "aa" (j - i = 1)
                    // - len 3: "aba" (j - i = 2) -> if s[i]==s[j], middle char is always valid
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // If s[i...j] is a palindrome and longer than our previous best, update
                if (dp[i][j] && (j - i + 1) > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};