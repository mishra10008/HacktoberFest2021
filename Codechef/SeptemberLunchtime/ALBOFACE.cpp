#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[2]={"Alice","Bob"};
void solve()
{
   ll n;
   cin>>n;
   cout<<s[(n+(!((n+1)&(n+2)) || !(n&(n+1))))%2]<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t=1;
  cin>>t;
  while(t--)
    solve();
  return 0;
}