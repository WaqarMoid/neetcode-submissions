class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible

        for (int num : nums) {
            // Backward traversal ensures each element is used at most once
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
