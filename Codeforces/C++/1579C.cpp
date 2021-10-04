#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod ((ll)1e9+7)
#define test ll t; cin>>t; while(t--)
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
void fileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {

	speed
	fileIO();
	test{
		ll n, m, k;
		cin >> n >> m >> k;
		char a[n][m];
		queue<pair<ll, ll>> q;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == '*') {
					q.push({i, j});
				}
			}
		}
		ll vis[n + 1][m + 1];
		memset(vis, 0, sizeof(vis));
		ll marked[n + 1][m + 1];
		memset(marked, 0, sizeof(marked));
		bool ok = 1;
		while (!q.empty()) {
			pair<ll, ll> p = q.front();
			q.pop();
			ll i = p.F, j = p.S;
			if (vis[i][j] > 100) {
				ok = 0;
				break;
			}
			ll ii = i - 1, jj = j - 1;
			ll cLeft = 0, cRight = 0;
			while (ii >= 0 && jj >= 0) {
				if (a[ii][jj] == a[i][j]) {
					cLeft++;
				}
				else break;
				ii--, jj--;
			}
			ii = i - 1, jj = j + 1;
			while (ii >= 0 && jj < m) {
				if (a[ii][jj] == a[i][j]) {
					cRight++;
				}
				else break;
				ii--, jj++;
			}
			vis[i][j]++;
			if (min(cRight, cLeft) >= k) {
				ll mini = min(cRight, cLeft);
				marked[i][j] = 1;
				ll ii = i - 1, jj = j - 1;
				while (ii >= 0 && jj >= 0 && mini > 0) {
					if (a[ii][jj] == a[i][j]) {
						vis[ii][jj]++;
						marked[ii][jj] = 1;
					}
					else break;
					mini--;
					ii--, jj--;
				}
				mini = min(cRight, cLeft);
				ii = i - 1, jj = j + 1;
				while (ii >= 0 && jj < m && mini > 0) {
					if (a[ii][jj] == a[i][j]) {
						vis[ii][jj]++;
						marked[ii][jj] = 1;
					}
					else break;
					mini--;
					ii--, jj++;
				}
			}
			else {
				q.push(p);
			}
		}
		ok = 1;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (a[i][j] == '*' && !marked[i][j]) {
					ok = 0;
					break;
				}
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}
