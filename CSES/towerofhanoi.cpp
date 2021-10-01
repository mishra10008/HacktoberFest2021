#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
#define pb push_back
#define fz(i,a,b) for(ll i=a; i<b; i++)
#define bz(i,a,b) for(ll i=a-1; i>=b; i--)
#define debug(x) cout << #x << " " << x << endl;
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
  #define debugger(x);
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

//tower of hanoi
//basically giving a recurssive approach for this problem
//moving the step from one part to other and then moving to the last



//first of all making a recurssive loop for this statement
//after that printing the loop one by one 

void solve(int a, int b, int c, int n) {
  if (n == 0)
  return;
  solve(a, c, b, n-1);
  cout<<a<<' '<<c<<endl;
  solve(b, a, c, n-1);
}


//basically taking the input and putting in this loop


int main()
{
  init();
  ll n;
  cin >> n;
  cout<< (1<<n) - 1<<endl;
  solve(1, 2, 3, n);

}


// thank you
//author
//pritish panda
    
