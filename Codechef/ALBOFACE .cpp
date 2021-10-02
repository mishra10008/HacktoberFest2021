//link-https://www.codechef.com/LTIME100B/problems/ALBOFACE
#include <bits/stdc++.h>
using namespace std;
struct win
{
    bool operator()(pair<int,int>a,pair<int,int>b)const
    {
        return (a.first<b.first) || (a.first==b.first && a.second>b.second);
    }
};
int main()
{
    long long int t=1;cin>>t;
    while(t--)
    {
        long long int n;cin>>n;
        if(n==1)
        {
            cout<<"Alice\n";
        }
        else
        {
            if(n&1LL)
            {
                n=n-1;
                long long int c=0;
                while(n)
                {
                    long long int c1=0;
                    while(n%2==0)
                    n=n/2,++c1;
                    n=n-1;
                    if(c1>=2) ++c;
                }
                if(c>=2) cout<<"Bob\n";
                else
                {
                    if(c==0) cout<<"Alice\n";
                    else cout<<"Bob\n";
                }
            }
            else
            {
                long long int c=0;
                while(n)
                {
                    long long int c1=0;
                    while(n%2==0)
                         n=n/2,++c1;
                    n=n-1;
                    if(c1>=2) ++c;
                }
               if(c>=2)
                cout<<"Alice\n";
                else
                {
                    if(c==0) cout<<"Bob\n";
                    else cout<<"Alice\n";
                }
            }
        }
    }
}
