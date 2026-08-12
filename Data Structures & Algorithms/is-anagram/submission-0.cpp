class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
            return false;
        }
        
        // Step 2: Frequency counter for 26 lowercase English letters
        vector<int> count(26, 0);
        
        // Step 3: Increment counts for 's' and decrement for 't'
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // Step 4: Verify all counts returned to 0
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        
        return true;    
    }
};
