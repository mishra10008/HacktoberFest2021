#leetcode problem 121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i,mini,maxi,ans;
        mini=prices[0];
        maxi=0;
        for (i=1;i<prices.size();i++)
       {
           if (prices[i]< prices[i-1])
               mini=min(mini,prices[i]);
            
            else
                
                maxi=max(maxi,prices[i]-mini);
       }
      
        return maxi;
    }
};