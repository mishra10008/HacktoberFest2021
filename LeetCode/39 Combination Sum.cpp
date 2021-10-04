class Solution {
public:

    // Backtracking problem
    
    vector<vector<int>>ans;
    
    void solve(int pos, int cur,int target, vector<int>& arr, vector<int>& temp)
    {
        // base cases
        if(cur < 0 || pos >= arr.size())
            return;
        
        if(cur == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = pos; i < arr.size(); i++)
        {
            temp.push_back(arr[i]);
            solve(i, cur - arr[i], target, arr, temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        solve(0,target,target,candidates,temp);
        return ans;
    }
};