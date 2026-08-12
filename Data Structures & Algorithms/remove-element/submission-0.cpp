class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int k = 0; // Pointer to place valid (non-val) elements

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is NOT equal to val, keep it
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};