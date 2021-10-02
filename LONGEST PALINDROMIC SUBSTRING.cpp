#include <bits/stdc++.h>

using namespace std;

    string longestPalin (string S) {
        
        if(S.size()==1)
        return S;
        
        string ans="";
  
      
      // CHECKING FOR LONGEST EVEN SIZED PALINDROMIC SUBSTRING 
      // like  aaaaBBaa :  BB will be equal and our algo will work accordingly
  for(int i=0;i<S.size()-1;i++)
  {
      int cnt=0;
      if(S[i]==S[i+1])
      {
          
          int a=i;
          int b=i+1;
          while(b<S.size())
          {
              if(S[a]==S[b])
              {
              cnt+=2;
              a--;
              b++;
              }
              else if(S[a]!=S[b])
              break;
          }
          if(cnt>ans.size())
          {
              ans.clear();
              ans=S.substr(a+1,cnt);
          }
      }
  }
  
  string ans2="";
      
      
      // CHECKING FOR LONGEST ODD SIZED SUBSTRING
      // LIKE aaaBaBaa : IN BaB , BB WILL BE EQUAL and our algo will work accordingly
    for(int i=0;i<S.size()-2;i++)
  {
      int cnt=0;
      if(S[i]==S[i+2])
      {
          cnt=1;
          int a=i;
          int b=i+2;
          while(b<S.size())
          {
              if(S[a]==S[b])
              {
              cnt+=2;
              a--;
              b++;
              }
              else if(S[a]!=S[b])
              break;
          }
          if(cnt>ans2.size())
          {
              ans2.clear();
              ans2=S.substr(a+1,cnt);
          }
      }
  }
  
      // RETURN THE MAXIMUM OF EVEN SIZED AND ODD SIZED PALINDROMIC SUBSTRING
  if(ans.size()>ans2.size())
  return ans;
      
  else if(ans.size()<ans2.size())
  return ans2;
      
  else if(ans.size()==ans2.size() && ans.size()>0)
  return ans;
      
  else
  {
      string a="";
      a+=S[0];
      return a;
  }
}

int main() {
	
	string s;
	cout<<"ENTER THE STRING";
	cin>>s;
	
	cout<<"\nLONGEST PALINDROMIC SUBSTRING IN **" <<s<<"** is: "<<longestPalin(s);

	return 0;
}
