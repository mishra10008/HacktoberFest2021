/*

Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum 
of elements in both subsets is equal.
First line of takes the size of array n, next line contain the n positive integers to be stored in array

Example 1
Input: 
4
1 5 11 5

Output: 
true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2
Input:
4
1 2 3 5

Output: 
false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100


*/

//Code is HERE

#include <bits/stdc++.h> 
using namespace std; 

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

void solve(){ 

    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution s;

    cout << s.canPartition(arr) << "\n";
} 
 
int32_t main(){ 

    solve();
} 
 
