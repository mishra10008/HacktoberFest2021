#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const ll mod=1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t=1;cin>>t;
    ll n,i,res,c;
    vector<ll>vec,a;

    for (i=2;i<=43;++i)
        vec.emplace_back(i);
    a.emplace_back(1);
    for (int i=0;i<42;++i){
        c = (a.back()*vec[i])/__gcd(a.back(),vec[i]);
        a.emplace_back(c);
    }

    while(t--){
        cin>>n; 
        res=0;
        vec.clear();
        a.clear();
        
            
        for(i=0;i<41;++i){
            c = ((n/a[i] - n/a[i+1])%mod *vec[i]%mod)%mod;
            (res+=c)%=mod;
        }
        cout<<res<<'\n';
    }


    return 0;
}
