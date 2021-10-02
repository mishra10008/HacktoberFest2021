// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
/*
  Description - 
  Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    string longestPalindrome(string s) {
              int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
      
        for(int i=n-1;i>=0;--i) {
           dp[i][i] = true;
          for(int j=i+1;j<n;++j) {
              if(j-i>1)
              dp[i][j] = (dp[i+1][j-1] && (s[i]==s[j]));
              else
                dp[i][j] = (s[i]==s[j]);
          }
        }

       int total = 1;
       int start = 0,end = 0;
      
      for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
          if(dp[i][j]) {
            if(j-i+1>total) {
               total = j-i+1;
               start = i;
               end  = j;
            }
          }
        }
      }
      
      return s.substr(start,end-start+1);
    }
};