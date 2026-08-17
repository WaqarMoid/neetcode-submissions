class Solution {
public:
    int numDecodings(string s) {
    int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // dp[i - 2]
        int prev1 = 1; // dp[i - 1]

        for (int i = 2; i <= n; i++) {
            int current = 0;

            // Check single digit
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                current += prev1;
            }

            // Check double digit
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1; 
    }
};
