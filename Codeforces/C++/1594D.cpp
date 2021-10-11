#include <bits/stdc++.h>
using namespace std;

int n,m,fa[400005];
int sz[400005];

int find(int x){
 if(fa[x]==x)return x;
 return fa[x]=find(fa[x]);
}

void merge(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx==fy)return;
  sz[fy]+=sz[fx];
  sz[fx]=0;
  fa[fx]=fy;
 
}

int work(){
  int ans=0;
  for(int i=1;i<=n;i++){
    if(find(i)==find(i+n))return -1;
    ans+=max(sz[i],sz[i+n]);
  }
  return ans;
}

int main(){
 
  int t;cin>>t;
  while(t--){
  cin>>n>>m;
    for(int i=1;i<=2*n;i++){
    sz[i]=i<=n;fa[i]=i;
    }
    for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      char s[20];
      scanf("%s",s);
      if(s[0]=='i'){
      merge(x,y+n);
      merge(x+n,y);
      }
      else{
      merge(x,y);
      merge(x+n,y+n);
      }
    }
    printf("%d\n",work());
  }
  return 0;
}
