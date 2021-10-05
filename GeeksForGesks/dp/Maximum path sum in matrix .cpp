//Maximum path sum in matrix 
//GfG practice link: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
//difficulty: medium

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for(int i=0;i<N;i++)
        dp[0][i]=Matrix[0][i];
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int a=j-1>=0?dp[i-1][j-1]:0;
                int b=j+1<N?dp[i-1][j+1]:0;
                int c=dp[i-1][j];
                dp[i][j]=max(a,max(b,c))+Matrix[i][j];
            }
        }
        int result=0;
        for(int i=0;i<N;i++)
        {
            result=max(result,dp[N-1][i]);
        }
       return result; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
