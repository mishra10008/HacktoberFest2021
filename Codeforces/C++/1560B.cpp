#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)

typedef vector<int> vi;
typedef long long ll;

/*********************************/

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<long long int> v;
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(c);
        ll temp = *max_element(all(v));
        if (abs(a - b) * 2 < temp)
        {
            cout << -1 << endl;
        }
        else
        {
            if (abs(a - b) < c)
            {
                cout << c - abs(a - b) << endl;
            }
            else
                cout << c + abs(a - b) << endl;
        }
    }
    return 0;
}