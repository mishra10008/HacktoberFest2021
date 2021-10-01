#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;

int unionOf2Arrays(int arr1[], int arr2[], int l, int n1, int n2)
{
    set<int> s1;
    int val = 0;
    for (int i = 0; i < n1; i++)
    {
        val = arr1[i];
        s1.insert(val);
    }
    for (int i = 0; i < n2; i++)
    {
        val = arr2[i];
        s1.insert(val);
    }
    cout << "\nUnion size : " << s1.size();
    cout << "\nUnion array : ";
    for (auto i = s1.begin(); i != s1.end(); i++) //?auto is necessary, int won't work!
    {
        cout << " " << *i;
    }

    return 0;
}
int intersectionOf2Arrays(int arr1[], int arr2[], int l, int n1, int n2)
{
    set<int> s1;
    set<int> s2;
    int val = 0;
    for (int i = 0; i < n1; i++)
    {
        val = arr1[i];
        s1.insert(val);
    }
    for (int i = 0; i < n2; i++)
    {
        val = arr2[i];
        set<int>::iterator it = s1.find(val);
        if (it != s1.end())
        {
            s2.insert(val);
        }
    }
    cout << "\nIntersection array size : " << s2.size();
    cout << "\nIntersection array : ";

    for (auto it1 = s2.begin(); it1 != s2.end(); ++it1) //?auto is necessary, int won't work!
    {
        cout << " " << *it1;
    }
    return 0;
}

int main()
{
    int n1, n2;
    cout << "Type the size of the array 1: ";
    cin >> n1;
    int arr1[1000], arr2[1000];
    cout << "\nEnter " << n1 << " elements for array 1 : ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "\nEntered elements in array 1 : ";
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nType the size of the array 2: ";
    cin >> n2;
    cout << "\nEnter " << n2 << " elements for array 2 : ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cout << "\nEntered elements in array 2 are : ";
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    unionOf2Arrays(arr1, arr2, 0, n1, n2);
    intersectionOf2Arrays(arr1, arr2, 0, n1, n2);
    return 0;
}