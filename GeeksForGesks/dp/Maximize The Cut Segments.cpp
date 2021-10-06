//Maximize The Cut Segments 
//GfG practice link:https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
//difficulty: medium


#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        int dp[n+1];
    
       dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            dp[i]=-1;
            if(x<=i)
            dp[i]=max(dp[i],dp[i-x]);
            if(y<=i)
            dp[i]=max(dp[i],dp[i-y]);
            if(z<=i)
            dp[i]=max(dp[i],dp[i-z]);
            if(dp[i]!=-1)
            dp[i]++;
            
        }
        return max(dp[n],0);
    
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
