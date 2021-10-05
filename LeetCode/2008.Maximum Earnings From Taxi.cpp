class Solution {
public:

    // O(nlog(n))
    // Top up approach
   
    long long dp[100005];
   
    
    
    long long solve(vector<vector<int>>& rides, int pos, int N)
    {
        // base condition
        if(pos >= N)
            return 0;
        
        
        if(dp[pos] != -1)
            return dp[pos];
        
        // we have 2 options 
        
        long long op1 =  solve(rides, pos + 1, N); // do not consider
        long long op2 =  rides[pos][1] - rides[pos][0] + rides[pos][2];   // consider
            
        long long x = rides[pos][1];
        long long low = pos + 1;
        long long high = N - 1;
        
        long long index = -1;
        
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            
            if(rides[mid][0] < x)
            {
                low = mid + 1;
            }
            else
            {
                index = mid;
                high = mid - 1;
            }
            
        }
        
        if(index != -1)
        {
            op2 += solve(rides, index, N);
        }
            
        return dp[pos] = std::max(op1, op2);
        
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        memset(dp, -1, sizeof(dp));
        
        int N = rides.size();
        
        sort(rides.begin(), rides.end());
        
        return solve(rides, 0, N);
        
    }
};