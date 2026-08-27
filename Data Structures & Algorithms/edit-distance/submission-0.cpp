class Solution {
public:
    int minDistance(string word1, string word2) {
    int m = word1.length();
        int n = word2.length();

        // dp[i][j] = min operations to convert word1[0...i-1] to word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: word2 is empty -> delete all characters from word1
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // Base case: word1 is empty -> insert all characters of word2
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // Fill table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Match: no cost added
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Mismatch: 1 + min(Insert, Delete, Replace)
                    int insertOp  = dp[i][j - 1];
                    int deleteOp  = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[m][n];    
    }
};
