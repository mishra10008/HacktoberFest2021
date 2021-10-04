#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
   int n,a,b,k,l=0;
   cin>>n>>a>>b;
   string s;
   cin>>s;
   if(b>0){
       cout<<n*(a+b)<<'\n';
       return;
   }
   int v[n],ans1=0,ans2=0;
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
       if(s[i]=='0' && v[i]==0){
           l=0;
           for(int j=i;j<n;j++){
               if(s[j]=='0'){
                   v[j]=1;
                   l++;
               }
               else{
                   break;
               }
           }
           ans1+=(a*l+b);
       }
   }
   l=0;
   for(int i=0;i<n;i++){
       if(s[i]=='1') l++;
   }
   ans1+=(a*l+b);
   
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
       if(s[i]=='1' && v[i]==0){
           l=0;
           for(int j=i;j<n;j++){
               if(s[j]=='1'){
                   v[j]=1;
                   l++;
               }
               else{
                   break;
               }
           }
           ans2+=(a*l+b);
       }
   }
   l=0;
   for(int i=0;i<n;i++){
       if(s[i]=='0') l++;
   }
   ans2+=(a*l+b);
   //cout<<ans1<<" "<<ans2<<'\n';
   cout<<max(ans1,ans2)<<'\n';
}
int main(){
  int tc=1;
  cin>>tc;
  while(tc--){
      solve();
  }
}
