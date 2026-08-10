class Solution {
public:
    public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Map each character to its rank/index
        int rank[26];
        for (int i = 0; i < order.length(); ++i) {
            rank[order[i] - 'a'] = i;
        }

        // Compare adjacent word pairs
        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            bool found_mismatch = false;
            int min_len = min(w1.length(), w2.length());

            for (int k = 0; k < min_len; ++k) {
                if (w1[k] != w2[k]) {
                    if (rank[w1[k] - 'a'] > rank[w2[k] - 'a']) {
                        return false;
                    }
                    found_mismatch = true;
                    break; // First mismatch is in correct order, check next pair
                }
            }

            // Prefix edge case: e.g., ["neetcode", "neet"]
            if (!found_mismatch && w1.length() > w2.length()) {
                return false;
            }
        }

        return true;
    }
};