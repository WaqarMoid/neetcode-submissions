class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size(), c = 0;
        
        for (int num : nums) {
            c += num;
        }

        // Target cannot exceed total sum, and (target + c) must be even and non-negative
        if (abs(target) > c || (target + c) % 2 != 0) {
            return 0;
        }

        int sum = (target + c) / 2;

        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        // Base case: 1 way to form sum 0 with 0 elements
        t[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};
