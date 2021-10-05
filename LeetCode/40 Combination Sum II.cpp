class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>& arr, int idx, int target,vector<int>& temp)
    {
        // base case
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < arr.size(); i++)
        {
            if(i > idx && arr[i] == arr[i - 1]) // condition to avoid duplicate combinations
            {
                continue;
            }
            
            if(arr[i] > target)
                break;
            
            temp.push_back(arr[i]);
            solve(arr, i + 1, target - arr[i], temp);
            temp.pop_back();
            
            
            
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<int>temp;
        solve(candidates, 0, target, temp);
        return ans;
    }
};