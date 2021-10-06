//Matrix Chain Multiplication
//GfG : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// C++
//Dificulty: Hard

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        if(N==2)
        return 0;
        if(N==3)
        return arr[0]*arr[1]*arr[2];
        int dp[N][N];
        int n=N;
        // code here
        for(int i=1;i<N;i++)
        {
        dp[i][i]=0;
        }
      for(int l=2;l<n;l++)
      {
          for(int i=1;i<n-l+1;i++)
          {
              int j=i+l-1;
              dp[i][j]=INT_MAX;
              for(int k=i;k<j;k++)
              {
                  dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
              }
          }
      }
      return dp[1][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
