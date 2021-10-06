//Word Break Problem 
//GfG practice link: https://practice.geeksforgeeks.org/problems/word-break1352/1
//difficulty: medium

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    if(B.size()==0)
    return 0;
 
        
        vector<bool> dp(A.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=A.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = A.substr(j,i-j);
                    if(count(B.begin(),B.end(),word)!=0)
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[A.size()];
    
}
