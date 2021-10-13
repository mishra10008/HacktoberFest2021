#include<bits/stdc++.h>

#define int long long
#define tses int testcases; cin >> testcases; while(testcases--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// pcode : MAGDOORS

using namespace std;

int32_t main(void){
  fio;
  
  tses{
    string s;
    cin >> s;

    int count = 0;
    char prev = '2';
    int first = 1;

    for(auto x: s){
      if(x == '1' and prev != '1' and first != 1){
        count++;
      }else if(x == '0' and prev != '0'){
        count++;
      }
      
      prev = x;
      first = 0;
    }

    cout << count << endl;
  }

  return 0;
}
