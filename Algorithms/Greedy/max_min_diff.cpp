#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long mn = 0,mx = 0;
    for (int i = 0; i < n/2; i++) {
        mx += (arr[i+n/2] - arr[i]);
        mn += (arr[2*i+1] - arr[2*i]);
    }
    cout<<mn<<" "<<mx;
    return 0;

}