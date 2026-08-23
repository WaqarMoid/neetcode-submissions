class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    int m = stones.size();
        int sum = 0;

        for (int s : stones) {
            sum += s;
        }
        int s = sum / 2;

        // DP table of size (m + 1) x (s + 1) initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(s + 1, 0));

        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < s + 1; j++) {
                if (i == 0) {
                    dp[i][j] = 0;
                }
                else if (j == 0) {
                    dp[i][j] = 0;
                }
                else if (stones[i - 1] <= j) {
                    // Include stone vs exclude stone
                    dp[i][j] = max(stones[i - 1] + dp[i - 1][j - stones[i - 1]], dp[i - 1][j]); 
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // dp[m][s] is the max weight S1 <= sum/2
        // Result is (sum - dp[m][s]) - dp[m][s]
        return sum - 2 * dp[m][s];
    }
};