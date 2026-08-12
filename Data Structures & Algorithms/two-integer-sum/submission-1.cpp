class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp; int c=0;
    for (int i=0;i<nums.size();i++)
        {   c=target-nums[i];
        if(mpp.find(c)!=mpp.end())
          return {mpp[c],i};
        mpp[nums[i]]=i;
        }
    return {};    
    }
};
