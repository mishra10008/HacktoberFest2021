#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n, k;
    cin >> n >> k;
    int arr[n];
    int a[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        a[i] = arr[i];
    }

    if (k == n - 1)
    {
        cout << -1 << endl;
    }
    else if (k == 0 && n % 2 != 0)
    {
        swap(arr[0], arr[n / 2]);
        reverse(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else if (k == 0 && n % 2 == 0)
    {
        reverse(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else if (n % 2 == 0 && k % 2 != 0)
    {

        int j;
        for (j = 0; j < k; j++)
        {
            cout << arr[j] << " ";
        }
        for (int i = n - 1; i >= k; i--, j++)
        {
            if (arr[i] == j + 1)
            {
                swap(arr[i], a[k]);
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {

        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = n - 1; i >= k; i--)
        {

            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}