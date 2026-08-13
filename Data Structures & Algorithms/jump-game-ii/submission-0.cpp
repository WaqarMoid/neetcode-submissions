class Solution {
public:
    int jump(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int maxreach=0;
    int current_end=0;
    int c=0;
    for(int i=0;i<nums.size() - 1;i++)
    {
        if(maxreach<i+nums[i])
        {
            maxreach=i+nums[i];
        }

        if(i == current_end)
        {
            c++;
            current_end = maxreach;
        }
    }    
    return c;
    }
};