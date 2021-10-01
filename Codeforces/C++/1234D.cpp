#include <bits/stdc++.h>
using namespace std;

# define TLEseBacho             ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
# define int                    long long int
# define printList(arr)         for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
# define inputList(arr)         for(int i=0;i<arr.size();i++){cin>>arr[i];}
# define itr(i,n)               for(i;i < n;i++)
# define vi                     vector<int>
# define vb                     vector<bool>
# define vc                     vector<char>
# define vp                     vector<pair<int,int>>
# define vvi                    vector<vector<int>>
# define vvc                    vector<vector<char>>
# define vvb                    vector<vector<bool>>
# define vvp                    vector<vector<pair<int, int>>>
# define pr                     pair<int, int>
# define add                    push_back
# define pqs                    priority_queue<int, vi, greater<int>>
# define pqb                    priority_queue<int>
# define modb                   1000000007
# define mods                   -1000000007
# define inf                    1e18
# define endl                   "\n"
# define endit                  cout << endl;

int getN(int sum) {
    sum = sum * 8;
    sum = sqrt(sum + 1) - 1;
    sum /= 2;
    return sum;
}

int apSum(int n) {
    int a = 1, d = 1;
    int res = (2 * a + (n - 1) * d) * n; res /= 2; return res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

/*--------------------------------------------------------------------------*/



vvi tree;
vc arr;
vi ans;
int newOne, oldOne;

void buildTree(int a, int b, int ind) {

    if (a == b) {
        tree[ind] = vi(26, 0);
        tree[ind][arr[a] - 'a'] += 1;
    }
    else {
        int m = (a + b) / 2;
        buildTree(a, m, ind * 2);
        buildTree(m + 1, b, ind * 2 + 1);

        tree[ind] = vi(26, 0);
        for (int i = 0; i < 26; i++) {
            tree[ind][i] = tree[ind * 2][i] + tree[ind * 2 + 1][i];
        }
    }
}


void replace(int a, int b, int ind, int pos, char ch) {

    if (a == b) {
        oldOne = arr[a] - 'a';
        newOne = ch - 'a';
        tree[ind][oldOne] -= 1;
        tree[ind][newOne] += 1;
        return;
    }

    int m = (a + b) / 2;
    if (pos <= m) {
        replace(a, m, ind * 2, pos, ch);
        tree[ind][oldOne] -= 1;
        tree[ind][newOne] += 1;
    }
    else {
        replace(m + 1, b, ind * 2 + 1, pos, ch);
        tree[ind][oldOne] -= 1;
        tree[ind][newOne] += 1;
    }

}

void rangeQuery(int a, int b, int l, int r, int ind) {

    if (l > r)
        return;
    if (a == l && b == r) {
        for (int i = 0; i < tree[ind].size(); i++) {
            ans[i] += tree[ind][i];
        }
    }
    else {

        int m = (a + b) / 2;
        rangeQuery(a, m, max(l, a), min(r, m), ind * 2);
        rangeQuery(m + 1, b, max(l, m + 1), min(r, b), ind * 2 + 1);
    }
}

void solveKaro() {

    string st;
    cin >> st;

    int n = st.length();
    arr = vc(n);
    for (int i = 0; i < n; i++)
        arr[i] = st[i];

    tree = vvi(4 * n);
    buildTree(0, n - 1, 1);

    int q;
    cin >> q;

    while (q--) {

        int mark;
        cin >> mark;

        if (mark == 1) {

            int pos; char ch;
            cin >> pos >> ch;
            replace(0, n - 1, 1, pos - 1, ch);
            arr[pos - 1] = ch;
        }

        else {

            int l, r;
            cin >> l >> r;
            ans = vi(26, 0);
            rangeQuery(0, n - 1, l - 1, r - 1, 1);
            int res = 0;
            // printList(ans);
            // endit;
            for (int i = 0; i < 26; i++) {
                if (ans[i] != 0)
                    res += 1;
            }

            cout << res << endl;
        }
    }
}

int32_t main() {

    TLEseBacho;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int tCase = 1;

    // cin >> tCase;

    while (tCase--) {

        solveKaro();

    }
}


/*------------------------------------------------------------------------*/