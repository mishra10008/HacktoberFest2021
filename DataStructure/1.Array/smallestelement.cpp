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
int partitionAlgo(int arr[], int l, int h, int pivot) //? refer Quick Sort Algorithm for partition part
{
    cout << "\nPivot element is : " << pivot << "\n";
    int i = l, j = l;
    while (i <= h)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (j - 1);
}

int quickSelect(int arr[], int l, int h, int k)
{
    int pivot = arr[h]; //assign last as pivot element
    int pi = partitionAlgo(arr, l, h, pivot);
    if (k > pi)
    {
        return quickSelect(arr, pi + 1, h, k);
    }
    else if (k < pi)
    {
        return quickSelect(arr, l, pi - 1, k);
    }
    else
    {
        return arr[pi];
    }
}

int main()
{
    int n = 5;
    int arr[5] = {12, 4, 57, 545, 34}, k = 0;
    cout << "Array is : \n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    int max = arr[0];

    //*first find the highest element in the array

    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "\nMaximum element in array : " << max << endl;
    cout << "\nInput which smallest element you want to print : ";
    cin >> k;

    //!then apply Quick Select algorithm
    int result = quickSelect(arr, 0, 5, k - 1);
    cout << k << " smallest element is : " << result;
}