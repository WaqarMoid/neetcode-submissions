class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mp; // hashing: num -> index
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i]; // complement
        if (mp.count(diff)) return {mp[diff], i}; // found
        mp[nums[i]] = i; // store number and index
    }
    return {};  
    }
};
