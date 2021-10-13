#include<bits/stdc++.h>
#include <vector>

#define int long long
#define tses int testcases; cin >> testcases; while(testcases--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// qcode : VACCINQ

using namespace std;

int32_t main(void){
  fio;
  
  tses{
    int n, p, x, y;
    cin >> n >> p >> x >> y;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < p; i++){
      if(arr[i] == 0){
        ans += x;
      }else{
        ans += y;
      }
    }

    cout << ans << endl;

  }

  return 0;
}
