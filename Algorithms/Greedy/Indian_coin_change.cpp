//Given a value V, if we want to make a change for V Rs, 
//and we have an infinite supply of each of the denominations in Indian currency, 
//i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
//what is the minimum number of coins and/or notes needed to make the change?


//Examples - Input: V = 70 , Output: 2
//We need a 50 Rs note and a 20 Rs note.

//Input: V = 121, Output: 3
//We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x; cin>>x;
    sort(a,a+n,greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }

    cout<<ans<<endl;
    return 0;
}