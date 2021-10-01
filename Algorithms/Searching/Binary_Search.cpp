
/* Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”,etc are subsequences of “abcdefg”. */
/*
Sample Input:
6 6
ABCDGH
AEDFHR

Output: 3


Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
*/



#include <bits/stdc++.h>
using namespace std;
  
// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int target)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        // Check if x is present at mid
        if (arr[m] == target)
            return m;
  
        // If x greater, ignore left half
        if (arr[m] < target)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
  
    // if we reach here, then element was
    // not present
    return -1;
}
  
int main(void)
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];              
    }

    int target;
    cin>>target;
    int result = binarySearch(a, 0, n - 1, target);
    if(result == -1) 
    cout << "Element is not present in array";
    else
    cout << "Element is present at index " << result;
    return 0;
}
