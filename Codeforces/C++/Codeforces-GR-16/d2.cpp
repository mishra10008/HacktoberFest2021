#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define lld long double
#define lli long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define INF 1e18
#define mod 1000000007
#include <string.h>

int main()
{
    FIO;
    ll t, a,b,n,m, k, i, j,cnt;
    cin>>t;
    string s,st;
    while(t--){
        ll n, m;
		cin >> n >> m;
		vector<ll> a(n * m);
		for (auto &x : a) cin >> x;

		map<ll, vector<ll>> mp;
		for (i = 0; i < n * m; i++) {
			mp[a[i]].push_back(i);
		}

		vector<ll> pos(n * m);

		ll r = 0, c = 0;
		for (auto &[x, v] : mp) {
			ll sz = (ll) v.size();
			for (k = 0; k < sz;) {
				ll left_over = sz - k;
				if (c + left_over < m) {
					for (j = c + left_over - 1; j >= c; j--) {
						pos[v[k++]] = r * m + j;
					}
					c += left_over;
				} else {
					for (j = m - 1; j >= c; j--) {
						pos[v[k++]] = r * m + j;
					}
					r += 1, c = 0;
				}
			}
		}

		vector<vector<ll>> pref(n, vector<ll>(m));

		ll ans = 0;
		for (i = 0; i < n * m; i++) {
			ll row = pos[i] / m, col = pos[i] % m;
			ans += pref[row][col];
			for (j = col; j < m; j++) {
				pref[row][j] += 1;
			}
		}

		cout << ans << '\n';

    }


    return 0;
}
