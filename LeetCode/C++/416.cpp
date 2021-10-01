class Solution {
public:
    vector<vector<int>> dp;
    bool get(int a, int sum, vector<int> &arr){
        
        if(sum <=0 || a>=arr.size()){
            if(sum == 0)
                return true;
            return false;
        }
        if(dp[a][sum]!=-1)
            return dp[a][sum] == 1;
        
        bool res1 = 0;
        if(sum - arr[a] >= 0)
        res1 = get(a+1, sum - arr[a], arr);
        int res2 = get(a+1, sum, arr);
        
        if(res1 == 1 || res2 == 1)
            dp[a][sum] = 1;
        else dp[a][sum] = 0;
        
        return dp[a][sum];
    }
    bool canPartition(vector<int>& arr) {
        
        int sum = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            sum+=arr[i];
        }
        if(sum % 2 == 1)
            return false;
        sum/=2;
        dp = vector<vector<int>>(n, vector<int>(sum+1, -1));
        return get(0, sum, arr);
    }
};