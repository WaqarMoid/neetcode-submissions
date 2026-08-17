class Solution {
public:
    int countSubstrings(string s) {
    int n = s.size();
        if (n == 0) return 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // If s[i...j] is a palindrome, increment the counter
                if (dp[i][j]) {
                    count++;
                }
            }
        }

        return count;    
    }
};
