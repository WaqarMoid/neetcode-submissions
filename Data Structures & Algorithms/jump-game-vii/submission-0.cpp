class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
        
        // t[i] stores the number of ways to reach index i
        vector<int> t(n, 0);
        t[0] = 1; // Base case: starting at index 0

        int count = 0; // Active reachable count in current window

        for (int j = 1; j < n; ++j) {
            // 1. Add the newly entered index into the window
            if (j - minJump >= 0) {
                count += t[j - minJump];
            }

            // 2. Remove the index that fell out of the window
            if (j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            // 3. Check if current spot j is reachable and valid ('0')
            if (count > 0 && s[j] == '0') {
                t[j] = 1; // Mark index j as reachable
            }
        }

        // Return whether the last index is reachable
        return t[n - 1] > 0;     
    }
};