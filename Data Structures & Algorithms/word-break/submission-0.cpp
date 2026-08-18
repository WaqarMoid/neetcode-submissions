class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
        
        // Put words in a hash set for O(1) average lookup time
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // dp[i] = true if substring s[0...i-1] (length i) can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string (length 0) is valid

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If the prefix of length j is valid...
                if (dp[j]) {
                    // ...check if the remaining piece s[j...i-1] is in the dictionary
                    string piece = s.substr(j, i - j);
                    
                    if (dict.count(piece)) {
                        dp[i] = true;
                        break; // Found a valid split for length i, move to next i
                    }
                }
            }
        }

        return dp[n];  
    }
};
