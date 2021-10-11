#include<bits/stdc++.h>
#define ll long long
ll p = 1000000007;
using namepsace std;
int main(){
	ll t,n,k,s,tmp;
  cin>>t;
	while(t--){
		s=0;tmp=1;
    cin>>n>>k;
		while(k){
			s=(s+(k&1)*tmp)%p;
			k>>=1;tmp=(tmp*n)%p;
		}
    cout<<s<<'\n';
	}
}
