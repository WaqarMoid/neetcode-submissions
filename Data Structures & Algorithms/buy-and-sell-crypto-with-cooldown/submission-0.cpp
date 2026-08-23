class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
        if (n <= 1) return 0;

        // dp[i][0] -> HELD
        // dp[i][1] -> SOLD
        // dp[i][2] -> REST
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Base cases on Day 0
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        // Fill 2D DP Table
        for (int i = 1; i < n; i++) {
            // Choice 1: Continue holding OR buy stock after resting
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);

            // Choice 2: Sell the stock held from previous day
            dp[i][1] = dp[i - 1][0] + prices[i];

            // Choice 3: Stay resting OR enter rest after yesterday's cooldown (sold)
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        // Maximum profit on the last day cannot be in the 'HELD' state
        return max(dp[n - 1][1], dp[n - 1][2]);    
    }
};
