#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
#define INF 1e9+7
 
/*#define debug(x);
printf(x);*/
 
void init()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
 
}
 
void  debugger()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
  #ifdef debugger
  #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
  #else
  #define debug(x);
  #endif
}
 
 
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
 
 
void precision(int a) 
{
  cout << setprecision(a) << fixed;
}
 
//** pritishcf307 **//
//**------------------------------------------------------------------------------------------------------**//
 
int main()
{
  init();
  ll x1,y1,x2,y2,x3,y3;
  ll a,b,c=0;
  lld slope1,slope2,slope3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  if(x2-x1==0)
  {
    slope1=1e9+7;
  }
  else
  {
    slope1=(0.1)*(y2-y1)/(0.1)*(x2-x1);
  }
  if(x3-x2==0)
  {
    slope2=1e9+7;
  }
  else
  {
    slope2=(0.1)*(y3-y2)/(0.1)*(x3-x2); 
  }
  if(x3-x1==0)
  {
    slope3=1e9+7;
  }
  else
  {
    slope3=(0.1)*(y3-y1)/(0.1)*(x3-x1);
  }
  //debug(slope1);
  //debug(slope2);
  //debug(slope3);
  if(slope1==slope2 && slope2==slope3 && slope1==slope3)
  {
    cout << 1 << endl;
  }
  else if( (slope1==0 && slope2==1e9+7) || (slope2==0 && slope1==1e9+7) )
  {
    cout << 2 << endl;
  }
  else if((slope2==0 && slope3==1e9+7) || (slope3==0 && slope2==1e9+7))
  {
    cout << 2 << endl;
  }
  else if((slope1==0 && slope3==1e9+7) || (slope3==0 && slope1==1e9+7))
  {
    cout << 2 << endl;
  }
  //debug(slope2);
  //debug(slope3);
  else if(slope1*slope2==-1)
  {
    cout << 2 <<  endl;
  }
  else if(slope2*slope3==-1)
  {
    cout << 2 <<  endl;
  }
   else if(slope1*slope3==-1)
  {
    cout << 2 <<  endl;
  }
 else if(x1==x2)
  {
    a=min(y1,y2);
    b=max(y1,y2);
    c=y3;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
  else
  {
    cout << 3 << endl;
  }
  }
  else if(x1==x3)
  {
    a=min(y1,y3);
    b=max(y1,y3);
    c=y2;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
    else
  {
    cout << 3 << endl;
  }
  }
  else if(x2==x3)
  {
    a=min(y2,y3);
    b=max(y2,y3);
    c=y1;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
    else
  {
    cout << 3 << endl;
  }
  }
  //debug(x1);
  //debug(x2);
  //debug(x3);
  //debug(y1);
  //debug(y2);
  //debug(y3);
  else if(y1==y2)
  {
    a=min(x1,x2);
    b=max(x1,x2);
    c=x3;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
    else
  {
    cout << 3 << endl;
  }
  }
  else if(y1==y3)
  {
    a=min(x1,x3);
    b=max(x1,x3);
    c=x2;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
    else
  {
    cout << 3 << endl;
  }
  }
  else if(y3==y2)
  {
    a=min(x3,x2);
    b=max(x3,x2);
    c=x1;
    if(c>=b||c<=a)
  {
    cout << 2 << endl;
  }
    else
  {
    cout << 3 << endl;
  }
  }
  //debug(slope1);
  //debug(slope2);
  //debug(slope3);
  else
  {
    cout << 3 << endl;
  }
  return 0;
} 
