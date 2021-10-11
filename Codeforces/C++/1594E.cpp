#include<bits/stdc++.h>
using namespace std;
long long n,p,f[61];
p=1000000007;
int main(){
  cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=(4*f[i-1]*f[i-1])%p;
    cout<<(6*f[n-1]*f[n-1])%p;
}
