#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define MAX 500

int multiply(int res[], int res_size, int i)
{
    int carry = 0;
    for (int x = 0; x < res_size; x++)
    {
        int prod = res[x] * i + carry;
        carry = prod / 10;
        res[x] = prod % 10;
    }

    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int i = 2; i <= n; i++)
    {
        res_size = multiply(res, res_size, i);
    }

    for (int i = res_size - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    cout << endl;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        factorial(n);
    }
    return 0;
}