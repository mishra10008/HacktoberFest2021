//Edit Distance Problem
//GfG practice link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1
//difficulty:medium


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    string s,p;
	    cin>>s;
	    cin>>p;
	 
	    int ss[a+1][b+1];
	    memset(ss,0,sizeof(ss));
	    for(int i=0;i<=a;i++)
	    {
	        for(int j=0;j<=b;j++)
	        {
	            if(i==0)
	            ss[i][j]=j;
	            else if(j==0)
	            ss[i][j]=i;
	            else if(s[i-1]==p[j-1])
	            {
	                ss[i][j]=ss[i-1][j-1];
	            }
	            else
	            {
	                ss[i][j]=1+min(ss[i-1][j-1],min(ss[i-1][j],ss[i][j-1]));
	            }
	        }
	    }
	    cout<<ss[a][b]<<"\n";
	}
	return 0;
}
