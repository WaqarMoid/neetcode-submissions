class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
        
        for (int num : nums) {
            // If number already exists in set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
     
    }
};