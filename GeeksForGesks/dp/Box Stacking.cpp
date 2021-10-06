// You can find this problem at GfG: https://practice.geeksforgeeks.org/problems/box-stacking/1
//Difficulty: medium topic: dynamic programming
//Hint: variation of longest increasing subsequence 

#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends

class box{
    public:
   int l,b,h;
    box(int ll,int bb,int hh)
    {
        l=ll;b=bb;h=hh;
    }
};

    
    bool myComp(box b1,box b2)
    {
        return ((b1.b)*(b1.l)<(b2.b)*(b2.l));
    }

class Solution
{
    
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<box>v;
      //  unordered_set<box>ssbx;
        for(int i=0;i<n;i++)
        {
            box bnew1= box(min(length[i],width[i]),max(length[i],width[i]),height[i]);
            v.push_back(bnew1);
            box bnew2= box(min(length[i],height[i]),max(length[i],height[i]),width[i]);
            v.push_back(bnew2);
            box bnew3= box(min(height[i],width[i]),max(height[i],width[i]),length[i]);
            v.push_back(bnew3);
        }
        sort(v.begin(),v.end(),myComp);
        int len=v.size();
        int dp[len];
        for(int i=0;i<len;i++)
        dp[i]=v[i].h;
        int ans=dp[0];
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j].b<v[i].b && v[j].l<v[i].l)
                {
                    dp[i]=max(dp[i],dp[j]+v[i].h);
                }
            }
            ans=max(ans,dp[i]);
        }
     
        return ans;
    }
};


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends
