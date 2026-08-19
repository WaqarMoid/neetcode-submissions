class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int single = 0;
        for (int x : nums) {
            single ^= x;
        }
        return single;    
    }
};
