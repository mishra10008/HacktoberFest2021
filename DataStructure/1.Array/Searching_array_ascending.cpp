// write an algorithm to find out whether given value existin matrix or not 
// but integer in row and column are given in ascending order.
# include <iostream>
using namespace std;
int main()
{
    int n,m;

    cout<<"Enter number of rows : ";
    cin>>n;

    cout<<"Enter number of column : ";
    cin>>m;

    int arr[n][m];
    cout<<"Enter elements of array :";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    int key;
    cout<<"Enter key u wanna search :";
    cin>>key;

    bool found = false;
    int r = 0, c = m-1;
    while(r < n and c >= 0)
    {
        if(arr[r][c]==key)
        {
          found = true;
          break;
        }
        else if(arr[r][c] > key)
        {
           c--;
        }
        else if(arr[r][c] < key)
        {
            r++;
        }
    }
    if(found)
    {
        cout<<"Element found at"<<" "<<r<<" "<<c<<endl;
    }
    else
    {
        cout<<"NOT FOUND\n";
    }
return 0;  
}
