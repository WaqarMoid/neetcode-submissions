class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> triplets;
    sort(nums.begin(), nums.end());
    // for(int num:nums)
    // s.insert(num);
    vector <int> k;
    for(int i=0;i<nums.size();i++)
    {   int left=i+1,right=nums.size()-1;
        while(left<right)
        { if(nums[left]+nums[right]+nums[i]==0)
            {triplets.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;}
          else if(nums[left]+nums[right]+nums[i]<=0)
                 left++;
          else if(nums[left]+nums[right]+nums[i]>=0)
                 right--;
        }
    }
     return vector<vector<int>>(triplets.begin(), triplets.end());
      
      
       }

    
};
