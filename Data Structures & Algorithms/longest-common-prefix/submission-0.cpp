class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
            return "";
        }
        
        // Step 2: Initialize prefix with the first string
        string prefix = strs[0];
        
        // Step 3: Compare prefix with every other string
        for (int i = 1; i < strs.size(); i++) {
            // Shorten prefix until strs[i] starts with prefix
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix shrinks to empty, no common prefix exists
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;    
    }
};