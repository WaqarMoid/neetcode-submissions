class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(),nums.end());
    int len=0;
    for (int num :nums)
    {if(s.find(num-1)==s.end())
    {int current =num;
    int l=1;

    while(s.find(current+1)!=s.end())
    {current++;
    l++;}

    if(l>len)
    len=l;
    }
    }
    return len;
    }
};
