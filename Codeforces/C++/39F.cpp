#include <bits/stdc++.h>
 
#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define REP(i,n) for(int i=0;i<n;i++)
#define w(t) int t; cin>>t; while(t--)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define M_PI 3.14159265358979323846
 
using namespace std;

int main(){
    fast;
    ll n,m,k; cin>>n>>m>>k;
    ll f[m];
    set<ll> mos;
    for(int i=0;i<m;i++ ) cin>>f[i];
    for(int i=0;i<k;i++) {ll x; cin>>x; mos.insert(x);}
    vector<pair<ll,ll>> v;
    for(int i=0;i<m;i++){
        ll freq=0;
        for(auto it=mos.begin();it!=mos.end();it++){
            if(*it%f[i]==0) freq++;
        }
        v.pb({freq,i+1}); 
    }
  //  cout<<endl;
    stable_sort(v.begin(),v.end());
    vector<int> ans; ans.pb(v[0].second);
    for(int i=1;i<v.size();i++){
        if(v[i].first==v[i-1].first) ans.pb(v[i].second);
        else break;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}