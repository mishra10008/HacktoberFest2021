#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
# define INF 0x3f3f3f3f 
const int MAX = 1e3 + 7; 
////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll base,ll por)
{
ll res=1;
while(por>1){
if(por%2==1)
{
res*=base;
por--;
}
por/=2;
base*=base;
}
res*=base;
return res;
}


/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    string bb;
    cin>>bb;
    ll a,co=0,c=0,d=0,b=0,k;
    n=bb.size();
    int aa[n+1][n+1];
    f(i,0,n+1)
    {
        f(j,0,n+1)
        {
            if(i==0)
            {
                aa[i][j]=1;
            }
            else if(i==1 && j>0)
            {
                aa[i][j]=1;
            }
            else if(i==2 && (j<n && j>0))
            {
                if(bb[j-1]==bb[j])
                {
                    aa[i][j]=1;
                }
                else
                {
                    aa[i][j]=0;
                }
            }
            else
            {
                aa[i][j]=0;
            }
        }
    }
    int x=-1,y=-1;
    f(i,3,n)
    {
        f(j,i,n+1)
        {
            if(bb[j-i]==bb[j-1] && aa[i-2][j-1]==1)
            {
                aa[i][j]=1;
                x=i;
                y=j;
            }
        }
    }
    cout<<x<<"\n";
    f(i,y-x,y)
    {
        cout<<bb[i];
    }
   return 0;
}