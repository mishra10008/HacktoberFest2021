#include <iostream>
#include<cmath>
using namespace std;
unsigned long long int check_prime(unsigned long long int a)
{
unsigned long long  int c;
 
   for ( c = 2 ; c*c <= a ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}
int main() {
int t;
cin >>t;
while(t--)
{
 unsigned long long int n;
    cin>>n;
    if(n==1)
    {
        cout <<"NO";
        cout <<endl;
    }
   else if(n==4)
    {
    cout <<"YES";
    cout <<endl;
    }
      else if(n%2==0)
    {
        cout << "NO";
        cout <<endl;
    }   
    else if(n%2==1)
    {
        long double f=sqrt(n);
        if(floor(f)==ceil(f))
        {
            int d=f;
            if(check_prime(d))
            {
                cout <<"YES";
                cout <<endl;
            }
            else
            {
            cout <<"NO";
            cout <<endl;
            }
        }
        else
        {
            cout <<"NO";
            cout <<endl;
        }
    }
}
	return 0;
}
