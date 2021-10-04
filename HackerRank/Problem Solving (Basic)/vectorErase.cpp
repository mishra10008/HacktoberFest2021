#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n, val;
    cin>>n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }

    int rem, head, rear;

    cin>>rem >>head >>rear;

    arr.erase(arr.begin()+(rem-1));

    arr.erase(arr.begin()+(head-1), arr.begin()+(rear-1));

    n=arr.size();
    cout<<n <<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<" ";
    }
    

    
    return 0;
}
