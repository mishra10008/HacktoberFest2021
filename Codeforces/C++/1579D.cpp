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
		ll n; cin >> n;
		priority_queue<pair<ll, ll>> pq;
		for (ll i = 0; i < n; i++) {
			ll x; cin >> x;
			pq.push({x, i});
		}
		vector<pair<ll, ll>> v;
		ll size = 0;
		while (pq.size() > 1) {
			pair<ll, ll> p1 = pq.top();
			pq.pop();
			pair<ll, ll> p2 = pq.top();
			pq.pop();
			p1.F -= 1;
			p2.F -= 1;
			if (p1.F >= 0 && p2.F >= 0) {
				v.push_back({p1.S + 1, p2.S + 1});
			}
			if (p1.F > 0)
				pq.push(p1);
			if (p2.F > 0)
				pq.push(p2);


		}
		cout << v.size() << endl;
		for (auto i : v) {
			cout << i.F << " " << i.S << endl;
		}

	}

	return 0;
}
