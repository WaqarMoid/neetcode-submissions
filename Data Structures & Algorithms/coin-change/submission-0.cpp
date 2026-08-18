class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int INF = amount + 1;
        vector<int> dp(amount + 1, INF);

        // Base case: 0 amount needs 0 coins
        dp[0] = 0;

        for (int c : coins) {
            for (int j = c; j <= amount; j++) {
                if (dp[j - c] != INF) {
                    dp[j] = min(dp[j], dp[j - c] + 1);
                }
            }
        }

        return dp[amount] >= INF ? -1 : dp[amount];   
    }
};
