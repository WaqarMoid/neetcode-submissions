class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    
    vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        // Amount outer, coins/nums inner -> Generates Permutations
        for (int j = 1; j <= target; j++) {
            for (int num : nums) {
                if (j >= num) {
                    dp[j] += dp[j - num];
                }
            }
        }

        return dp[target];

    }
};