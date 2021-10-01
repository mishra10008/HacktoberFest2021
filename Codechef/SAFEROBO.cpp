//https://www.codechef.com/problems/SAFEROBO
/*
Sample Input:
2
A..B
1 1
A...B
1 1
Sample Output:
safe
unsafe
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {   string s;
        cin>>s;
        int sa,sb;
        cin>>sa>>sb;
        int p,q;
        p=s.find('A');
        q=s.find('B');
        while(p<q)
        {
            p=p+sa;
            q=q-sb;
        }
        if(p==q)
        cout<<"unsafe\n";
        else
        cout<<"safe\n";
    }
    return 0;
}


//----------------- 
// count length of  longest substring with same character

#include<bits/stdc++.h>
using namespace std;
int maxPower() 
    {int maxlen=1;
     string s;
     cin>>s;
int temp=1;
  for(int i=1;i<s.length();i++)
  {
if(s[i]==s[i-1])
temp++;
else
{
    maxlen=temp>maxlen?temp:maxlen;
    temp=1;
}

   
   }
   maxlen=temp>maxlen?temp:maxlen;
     cout<<maxlen<<endl;
return maxlen;

}
int main()
{
    maxPower();
    return 0;
}
