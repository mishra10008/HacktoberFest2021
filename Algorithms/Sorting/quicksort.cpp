#include<bits/stdc++.h>
using namespace std;

//Quick Sort Implementation

int K = 0; int n;

//arrange the elements right and left so that all left elements are small and all right elements are greater
int arrange(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    return i + 1;
}

//randomized partition function
int partition(int *arr, int low, int high)
{
    srand(time(0));
    int random = low + (rand() % (high - low));
    swap(arr[random], arr[high]);
    return arrange(arr, low, high);
}

//quick funtion that calls partition and sorts recursively by arranging one element
void quicksort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
    return;
}

int main()
{
    //taking inputs
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //starting timer before sort
    auto start = std::chrono::system_clock::now();
    //sorting
    quicksort(arr, 0, n - 1);
    //stoping the timer
    auto end = std::chrono::system_clock::now();
    //calculating the time taken by quick sort and printing
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    //printing the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    //deleting the array
    delete []arr;
    return 0;
}