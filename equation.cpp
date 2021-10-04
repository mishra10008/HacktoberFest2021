#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
 
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
bool check(ll n)
{
  ll j;
  j=sqrt(n);
  if(j*j==n)
  {
    return true;
  }
  else
  {
    return false;
  }
  return 0;
}
 
int main()
{
  init();
  lld a,b,c;
  ll ans;
  lld disc,disc1;
  lld p,q;
  lld a1,a2;
  cin >> a >> b >> c;
  if(a==0 && b==0 && c==0)
  {
    cout << -1 <<  endl;
    
  }
  else if(a==0 && b==0 && c!=0)
  {
    cout << 0 <<  endl;
  }
  else if(a==0 && c==0 && b!=0)
  {
    ans=1;
    cout << ans << endl;
    precision(10);
    cout << 0.00000000 << endl;
  }
  else if(b==0 && c==0 && a!=0)
  {
    ans=1;
    cout << ans << endl;
    precision(10);
    cout << 0.0000000 << endl;
  }
  else if(a==0 && b!=0 && c!=0)
  {
    ans=1;
    cout << ans << endl;
     precision(10);
    cout << (-1.0*c)/b << endl;
  }
  else if(a!=0 && b!=0 && c==0)
  {
    ans=2;
    cout << ans << endl;
    precision(10);
    a1= 0;
    a2=(-1.0*b)/a;
    if(a1>a2)
    {
      swap(a1,a2);
    }
      cout << a1 << endl << a2 << endl;
  }
  else if(a!=0 && b==0 && c!=0)
  {
    if(c>0)
    {
      cout << 0 << endl;
    }
    else if(c<0)
    {
      ans=2;
      cout << ans << endl;
      precision(10);
      a1 = +1.0*sqrt(c/a);
      a2 = -1.0*sqrt(c/a);
       if(a1>a2)
      {
      swap(a1,a2);
      }
      cout << a1 << endl << a2 << endl;
    }
  }
  else if(a!=0 && b!=0 && c!=0)
  {
    disc1= ((b*b) - 4*a*c);
    if(disc1>0)
    {
      ans=2;
      cout << ans << endl;
      precision(10);
      a1 = ((-1.0*b)-sqrt(disc1))/(2*a);
      a2 = ((-1.0*b)+sqrt(disc1))/(2*a);
      if(a1>a2)
      {
      swap(a1,a2);
      }
      cout << a1 << endl << a2 << endl;
    }
    else if(disc1==0)
    {
      ans=1;
      cout << ans << endl;
      precision(10);
      cout << (-1.0*(b))/(2*a);
    }
    else if(disc1 < 0)
    {
      cout << 0 << endl;
    }
  }
  return 0;
}
 //author
//pritish panda
  
