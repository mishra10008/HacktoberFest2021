// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the missing elements
vector<int> missing_elements(vector<int> vec)
{

    // Vector to store the list
    // of missing elements
    vector<int> mis;

    // For every given element
    for (int i = 0; i < vec.size(); i++)
    {

        // Find its index
        int temp = abs(vec[i]) - 1;

        // Update the element at the found index
        vec[temp] = vec[temp] > 0 ? -vec[temp] : vec[temp];
    }
    for (int i = 0; i < vec.size(); i++)

        // Current element was not present
        // in the original vector
        if (vec[i] > 0)
            mis.push_back(i + 1);

    return mis;
}

// Driver code
int main()
{
    vector<int> vec = {3, 3, 3, 5, 1};

    // Vector to store the returned
    // list of missing elements
    vector<int> miss_ele = missing_elements(vec);

    // Print the list of elements
    for (int i = 0; i < miss_ele.size(); i++)
        cout << miss_ele[i] << " ";

    return 0;
}
