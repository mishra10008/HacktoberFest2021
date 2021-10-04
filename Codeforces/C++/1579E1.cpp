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
		ll a[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		deque<ll> dq;
		for (ll i = 0; i < n; i++) {
			if (dq.size() == 0) {
				dq.push_back(a[i]);
			}
			else {
				if (a[i] < dq.front()) {
					dq.push_front(a[i]);
				}
				else dq.push_back(a[i]);
			}

		}
		for (auto i : dq) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
