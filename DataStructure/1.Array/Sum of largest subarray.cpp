#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    int maxSum=INT_MIN;
    /* //O(n^3)
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currsum=0;
            for(int k=i;k<=j;k++)
            {
                currsum+=arr[k];
            }
            if(currsum>maxSum)
            maxSum=currsum;
        }
    }

*/

/*
//O(n^2)
int *sum=new int[n];
sum[0]=arr[0];
for(int i=1;i<n;i++)
{
sum[i]=sum[i-1]+arr[i];
}
        for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currsum=sum[j]-sum[i]+arr[i];
          
            if(currsum>maxSum)
            maxSum=currsum;
        }
    }
    */
   //O(n)
int cursum=0;
    for(int i=0;i<n;i++)
    {
        cursum+=arr[i];
        if(cursum>maxSum)
        maxSum=cursum;
        if(cursum<0)
        cursum=0;
    }
    cout<<maxSum<<endl;
    return 0;
}
//2 -3 2 4 -1 2 3 -2
