class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int l=0,r=1,max=0;
    while(r<prices.size())
    { if(prices[r]>prices[l])
        {int profit= prices[r]-prices[l];
        if(profit>max)
           max=profit;
        }
     else
        l=r;
    r++;
    }
    return max; 
    }   
    
};
