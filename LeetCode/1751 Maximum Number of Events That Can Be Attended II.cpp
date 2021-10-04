class Solution {
public:
    
    // Top down Approach

    vector<vector<int>>dp;
    
    int solve(vector<vector<int>>& events, int pos, int k)
    {
        if(pos >= events.size() || k == 0)
            return 0;
        
        if(dp[pos][k] != -1)
            return dp[pos][k];
        
        int op1 = solve(events, pos + 1, k);
        int op2 = events[pos][2];
        
        
        int low = pos;
        int high = events.size() - 1;
        int index = -1;
        int cur_end = events[pos][1];
        
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(events[mid][0] > cur_end)
            {
                index = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        if(index != -1)
        {
            op2 += solve(events, index, k-1);
        }
        
        return dp[pos][k] = std::max(op1,op2);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end());
        
        const int n = events.size();
        
        dp.resize(n + 1, vector<int>(k + 1, -1));
        
        
        return solve(events, 0, k);
        
    }
};