class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int s=0;
    int max=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        s+=nums[i];
        if(s>max)
        max=s;

        if(s<0)
        s=0;
    }
    return max;
    }
};
