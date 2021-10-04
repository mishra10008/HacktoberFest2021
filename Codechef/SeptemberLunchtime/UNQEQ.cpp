#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n%4 != 0)
    {
        cout<<"NO"<<"\n";
        return ;
    }
    cout<<"YES"<<"\n";
    vector<int>v1;
    vector<int>v2;
    
    int a=1;
    int b=n;
    
    int flag =0;
    int check = n/2;
    while(check)
    {
        if(flag == 0)
        {
            v1.push_back(a);
            a++;
            flag = 1;
        }
        else
        {
            v1.push_back(b);
            b--;
            flag=0;
        }
        check--;
    }
    
    
    for(int i=a;i<=b;i++)
    {
        v2.push_back(i);
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(auto val:v1)
    cout<<val<<" ";
    cout<<"\n";
    for(auto val:v2)
    cout<<val<<" ";
    cout<<"\n";
    return ;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}