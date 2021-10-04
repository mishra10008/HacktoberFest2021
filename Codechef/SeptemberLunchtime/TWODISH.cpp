#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a,b,c;
	    cin>>n>>a>>b>>c;
	    int x;
	    x= a+c;
	    if(x>=n && b>=n)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	    
	}
	return 0;
}