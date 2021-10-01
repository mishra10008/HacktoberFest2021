/* Problem Statement -: 
Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Example 1:

Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string
with the same case of character as that
in original string is deeIRSfrsTUX
Example 2:

Input:
N = 6
S = srbDKi
Output: birDKs
Explanation: Sorted form of given string
with the same case of character will
result in output as birDKs.
Your Task:
You only need to complete the function caseSort that returns sorted string.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 103 */

//Solution -:
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string lstr = "",ustr="",resultstr="";
        int arr[n];
        for(int i=0;i<n;i++){
            if(islower(str[i])){
                arr[i]=0;
                lstr+=str[i];
            }else if(isupper(str[i])){
                arr[i]=1;
                ustr+=str[i];
            }
        }
        sort(lstr.begin(),lstr.end());
        sort(ustr.begin(),ustr.end());
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(arr[k]==0){
                resultstr+=lstr[i];
                i++;
            }
            else if(arr[k]==1){
                resultstr+=ustr[j];
                j++;
            }
        }
        return resultstr;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends
