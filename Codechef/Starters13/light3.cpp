#include<bits/stdc++.h>

#define int long long
#define tses int testcases; cin >> testcases; while(testcases--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// pcode : DIWALI1

using namespace std;

int32_t main(void){
  fio;
  
  tses{
    int P, a, b, c, x, y;
    cin >> P >> a >> b >> c >> x >> y;
    
    int ans = 0;

    if((b+x*a) <= (c+x*a)){
      ans = x * a + b;
      ans = P / ans;
    }else{
      ans = y * a + c;
      ans = P / ans;
    }

    cout << ans << endl;
  }

  return 0;
}
