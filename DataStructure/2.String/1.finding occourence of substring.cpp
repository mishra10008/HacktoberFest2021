#include<bits/stdc++.h>
using namespace std;
static int x = []() {
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0; }();
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewels = 0;
        for(char j : J){
            for(char s : S){
                if(j == s){
                    jewels++;
                }
            }
        }
        return jewels;
    }
};
/* o(N)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char seen[58] = {0};
        int ans = 0;
        for (auto ch : S) {
            seen[ch - 'A'] += 1;
        }
        for (auto ch : J) {
            ans += (int) seen[ch - 'A'];
        }
        return ans;
    }
}; */
int main()
{
    //https://theasciicode.com.ar/extended-ascii-code/letter-i-umlaut-diaeresis-ascii-code-216.html
    //A-65 se Z-90   a-97  z-122

    /*
    int a=204;
    char b=a;
    cout<<b;
*/
	Solution ob;
	string  j="aA";
	string s="aAbAabA";
cout<<ob.numJewelsInStones(j,s);
return 0;
}

