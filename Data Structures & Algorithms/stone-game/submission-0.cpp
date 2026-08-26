#include <cstring>
class Solution {
private:
    int memo[501][501];

    int solve(int l, int r, vector<int>& piles) {
        // Base case: only 1 pile left, the current player takes it directly
        if (l == r) {
            return piles[l];
        }

        if (memo[l][r] != -1) {
            return memo[l][r];
        }

        // Choice 1: Pick the left pile
        int pickLeft = piles[l] - solve(l + 1, r, piles);

        // Choice 2: Pick the right pile
        int pickRight = piles[r] - solve(l, r - 1, piles);

        return memo[l][r] = max(pickLeft, pickRight);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof(memo));

        // Alice starts first on [0 ... n - 1].
        // If her net score advantage over Bob is > 0, Alice wins.
        return solve(0, n - 1, piles) > 0;
    }
};