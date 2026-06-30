class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, r = 0, maxlen = 0;
        
        while (r < s.length()) {
            if (seen.find(s[r]) == seen.end()) {
                seen.insert(s[r]);
                int len = r - l + 1;
                if (len > maxlen)
                    maxlen = len;
                r++;
            } else {
                seen.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};


