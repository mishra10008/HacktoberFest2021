class Solution {
public:
    
    // *************BOTTOM UP APPROACH *******************8
    // T.c O(n*amount)
    
    int coinChange(vector<int>& coins, int amount) {
        
        const int N = coins.size();
        vector<int>dp, visited;
        dp.resize(amount + 1, amount + 1);
        visited.resize(amount + 1, 0);
        
    
        dp[0] = 0;
        
    
        
        for(int i = 1; i <= amount; i++)
        {
            for(int coin : coins)
            {
                if(coin <= i)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};