#include <cstring>
class Solution {
private:
    int memo[305][305];

    int solveMemo(int i, int j, vector<int>& nums) {
        // Base case: no balloon between i and j
        if (i + 1 >= j) {
            return 0;
        }

        // Return cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxCoins = 0;

        // Try bursting each balloon k last in range (i, j)
        for (int k = i + 1; k < j; k++) {
            int coins = nums[i] * nums[k] * nums[j] 
                        + solveMemo(i, k, nums) 
                        + solveMemo(k, j, nums);

            maxCoins = max(maxCoins, coins);
        }

        return memo[i][j] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        // Pad array with 1 at both ends
        vector<int> arr = {1};
        arr.insert(arr.end(), nums.begin(), nums.end());
        arr.push_back(1);

        int n = arr.size();
        memset(memo, -1, sizeof(memo));

        return solveMemo(0, n - 1, arr);
    }
};
