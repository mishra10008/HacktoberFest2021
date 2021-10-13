#include<bits/stdc++.h>

#define int long long
#define tses int testcases; cin >> testcases; while(testcases--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// pcode : SUPCHEF

using namespace std;

int32_t main(void){
  fio;
  
  tses{
    int m, n, k;
    cin >> m >> n >> k;

    int time = n*k;
    if(time >= m) cout << "NO";
    else cout << "YES";
  }

  return 0;
}
