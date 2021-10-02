#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int arr[n]={0};
    int j=2,d=a[1]-a[0],k=0;
    for(int i=2;i<n;i++)
    {
        if(a[i]-a[i-1]==d)
          j++;
        else if(a[i]-a[i-1]!=d)
        {
            d=a[i]-a[i-1];
            arr[k]=j;
            k++;
            j=2;
        }
    }
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    cout<<max;
	return 0;
}
