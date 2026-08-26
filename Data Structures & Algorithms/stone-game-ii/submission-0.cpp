class Solution {
public:
    int stoneGameII(vector<int>& piles) {
    int n = piles.size();
        vector<int> suffixSum(n + 1, 0);

        // Precompute suffix sums
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // dp[i][M] represents max stones a player can get from piles[i...n-1] with parameter M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate backwards through start indices i
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                // If the player can take all remaining stones in one move
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                } else {
                    for (int X = 1; X <= 2 * M; X++) {
                        int nextM = max(M, X);
                        dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][min(n, nextM)]);
                    }
                }
            }
        }

        return dp[0][1];    
    }

    
};