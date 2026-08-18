class Solution {
public:
    int n;
    vector<int> t; // 1D memoization table

    int solve(vector<int>& stones, int i) {
        // Base case: if all stones are exhausted
        if (i >= n) {
            return 0;
        }

        // Return memoized result if already computed
        if (t[i] != -1) {
            return t[i];
        }

        int result = INT_MIN;

        // Possibility 1: Take 1 stone (stones[i])
        result = stones[i] - solve(stones, i + 1);

        // Possibility 2: Take 2 stones (stones[i] + stones[i+1])
        if (i + 1 < n) {
            result = max(result, stones[i] + stones[i + 1] - solve(stones, i + 2));
        }

        // Possibility 3: Take 3 stones (stones[i] + stones[i+1] + stones[i+2])
        if (i + 2 < n) {
            result = max(result, stones[i] + stones[i + 1] + stones[i + 2] - solve(stones, i + 3));
        }

        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        
        // Initialize memo table of size n+1 with -1
        t.resize(n + 1, -1);

        // solve(stones, 0) calculates (Alice Score - Bob Score)
        int diff = solve(stoneValue, 0);

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        }

        return "Tie";
    }
};