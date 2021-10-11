#include<bits/stdc++.h>
using namespace std;
char a[300010],c[5];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n>>c>>(a+1);
		for (int i=1;i<=n;i++){
			ans=i;
			for(int j=i;j<=n;j+=i)if(a[j]!=c[0])ans=0;
			if(ans)break;
		}
		if(ans==1){
      cout<<"0\n";
    }
		else if(ans>1){
      cout<<"1\n"<<ans;
    }
		else{
      cout<<"2\n"<<n-1<<" "<<n;
    }
	}
	return 0;
}
