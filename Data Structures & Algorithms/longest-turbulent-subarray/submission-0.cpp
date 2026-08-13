class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
    int n=arr.size();
    int l=1,maxl=1,prevsign=0;
    if(n==1) return 1;

    for(int i=1;i<n;i++)
    {
        int sign=0;
        if(arr[i]<arr[i-1]) sign=-1;
        else if(arr[i]>arr[i-1]) sign=1;
        
        if(sign==0)
        {
            l=1;
        }
        else if(sign==-prevsign)
        {
            l++;
        }
        else
        {
            l=2;
        }

        prevsign=sign;
        maxl=max(l,maxl);
    }
    return maxl;  
    }
};