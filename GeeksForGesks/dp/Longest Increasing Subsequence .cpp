//Longest Increasing Subsequence 
//GfG: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//difficulty: medium
//time complexity: nlogn


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int search(int l,int r,int n,int dp[]){
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(dp[mid]>=n)
            r=mid;
            else
            l=mid+1;
        }
        return r;
    }
    int longestSubsequence(int n, int arr[])
    {
       int dp[n];
       int length=1;
       dp[0]=arr[0];
       for(int i=1;i<n;i++)
       {
           if(arr[i]>dp[length-1])
           {
               dp[length]=arr[i];
               length++;
           }
           else
           {
               int lower=search(0,length-1,arr[i],dp);
               dp[lower]=arr[i];
           }
       }
       return length;


    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
