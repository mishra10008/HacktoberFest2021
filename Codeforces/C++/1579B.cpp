#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod ((ll)1e9+7)
#define test ll t; cin>>t; while(t--)
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
		ll n; cin >> n;
		vector<ll> a(n), b(n);
		map<ll, ll> mp;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
			mp[a[i]]++;
		}
		sort(b.begin(), b.end());
		ll vis[n];
		memset(vis, 0, sizeof(vis));
		vector<pair<ll, pair<ll, ll>>> v;
		for (ll i = 0; i < n; i++) {
			ll val = b[i];
			ll index = 0;
			for (ll j = i; j < n; j++) {
				if (a[j] == val && mp[a[j]] > 0) {
					index = j;
					break;
				}
			}
			mp[a[index]]--;
			if (index != i && i < n) {
				rotate(a.begin() + i, a.begin() + index, a.end());
				v.push_back({i + 1, {n, abs(index - i)}});
			}
		}
		if (v.size() == 0) {
			cout << 0 << endl;
		}
		else{
			cout << v.size() << endl;
			for (auto i : v) {
				cout << i.first << " " << i.second.first << " " << i.second.second << endl;
			}
		}

	}

	return 0;
}
