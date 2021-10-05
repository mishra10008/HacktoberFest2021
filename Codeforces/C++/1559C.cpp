// Problem Link: https://codeforces.com/contest/1559/problem/C

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;

    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[n - 1] == 0)
    {
        for (int i = 0; i <= n; i++)  cout << i + 1 << " ";
        cout << endl;
        return;
    }

    long long int b[n + 1] = {};
    long long int t = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0) continue;

        if (a[i - 1] == 0 && a[i] == 1)
        {
            t = i;
            break;
        }
    }

    b[t] = n + 1;
    b[t - 1] = t;


    for (int i = 0; i < t; i++) cout << i + 1 << " ";

    for (int i = t; i <= n; i++)
    {
        if (b[i]) cout << b[i] << " ";
        else cout << i << " ";
    }

    cout << endl;

}

int main()
{

    long long int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}