#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int arr[], int i, int j) //?part of partitioning the array into two parts divided by pivot element
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int negToBeg(int arr[], int l, int h) //! Variant of partitioning algorithm
{
    //? 2 section -> arr[ {0 to k}        {(k+1) to end} ]
    //? {0 to (k)} = numbers less than zeroes
    //? {(k+1) to end} = numbers greater than zeroes

    int i, k;
    i = 0;
    k = h - 1;
    cout << "\n Value of i : " << i << "\n Value of k : " << k;
    while (i < k) // as soon as i crosses k , we can be sure that whole array has been traversed
    {
        if (arr[i] < 0)
        {
            i++; //* if arr[i] < 0 then move i
        }
        else
        {
            swap(arr, i, k);
            k--;
        }
    }
    return arr[h];
}

int main()
{
    int n;
    cout << "Type the size of the array : ";
    cin >> n;
    int arr[1000];
    cout << "\nEnter " << n << " elements including negative and positive values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEntered elements in array including negative and positive values are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    negToBeg(arr, 0, n);
    cout << "\nSorted array including negative and positive values is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//!Reference : https://www.youtube.com/watch?v=MbV26HWqxrs