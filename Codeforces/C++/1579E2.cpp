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
struct Query
{
	ll l, r, x, idx;
};
struct ArrayElement
{
	ll val, idx;
};

bool cmp1(Query q1, Query q2)
{
	return q1.x < q2.x;
}

bool cmp2(ArrayElement x, ArrayElement y)
{
	return x.val < y.val;
}

void update(ll bit[], ll idx, ll val, ll n)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

ll query(ll bit[], ll idx, ll n)
{
	ll sum = 0;
	for (; idx > 0; idx -= idx & -idx)
		sum += bit[idx];
	return sum;
}

void answerQueries(ll n, Query queries[], ll q,
                   ArrayElement arr[], vector<ll>&anss)
{
	ll bit[n + 1];
	memset(bit, 0, sizeof(bit));

	sort(arr, arr + n, cmp2);

	sort(queries, queries + q, cmp1);
	ll curr = 0;

	for (ll i = 0; i < q; i++)
	{
		while (arr[curr].val <= queries[i].x && curr < n)
		{
			update(bit, arr[curr].idx + 1, 1, n);
			curr++;
		}

		anss[queries[i].idx] = query(bit, queries[i].r + 1, n) -
		                       query(bit, queries[i].l, n);
	}
}
int main() {

	speed
	fileIO();
	test{
		ll n; cin >> n;
		vector<ll> a(n);
		ArrayElement arr[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			arr[i].val = a[i];
			arr[i].idx = i;
		}
		Query queries[n - 1];

		for (ll i = 1; i < n; i++) {
			queries[i - 1].l = 0, queries[i - 1].r = i - 1, queries[i - 1].x = a[i];
			queries[i - 1].idx = i - 1;
		}
		vector<ll> anss(n - 1);
		answerQueries(n, queries, n - 1, arr, anss);
		ll ans = 0;
		map<ll, ll> mp;
		for (ll i = 0; i < n; i++) {
			if (i == 0) {
				mp[a[i]]++;
			}
			else {
				ll smallerEqual = anss[i - 1];
				ll smaller = 0;
				ll greater = i - smallerEqual;
				if (mp.find(a[i]) == mp.end()) {
					smaller = smallerEqual;
				}
				else smaller = smallerEqual - mp[a[i]];
				ans += min(smaller, greater);
				mp[a[i]]++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
