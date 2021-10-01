#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    cout << "===================================REVERSE AN ARRAY====================================\n";
    int n = 10;
    int a[10];
    cout << "Give 10 numbers as input to the array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The given array is : \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nThe reversed array is : \n\n";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
        / time complexity : O(n) /
    }
}