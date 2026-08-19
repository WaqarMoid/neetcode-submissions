class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;          // Line 1
        while (n != 0) {         // Line 2
            n = n & (n - 1);    // Line 3
            count++;            // Line 4
        }
        return count;
    }
};
