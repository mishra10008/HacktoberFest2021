class Solution {
public: 

    // T.C O(n^2)
    int longestArithSeqLength(vector<int>& A) { 
        
        
        const int N = A.size();
        
        if(N <= 2)
            return N;
        
        vector<vector<int>>dp;
        
        dp.resize(N, vector<int>(1001,1));
        
        int ans = INT_MIN;
        
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j] + 500; // to handle negative difference
                
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                
                ans = max(ans, dp[i][diff]);
                
            }
        }
        
        
        return ans;
        
        
        
    }
};