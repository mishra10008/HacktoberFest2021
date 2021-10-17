//https://www.codechef.com/START15C/problems/SUBTASK

/*
A Subtask Problem Problem Code: SUBTASKSolvedSubmit (Practice)
Chef recently solved his first problem on CodeChef. The problem he solved has N test cases. He gets a score for his submission according to the following rules:

1) If Chef’s code passes all the N test cases, he gets 100 points.

2) If Chef’s code does not pass all the test cases, but passes all the first M(M<N) test cases, he gets K(K<100) points.

3) If the conditions 1 and 2 are not satisfied, Chef does not get any points (i.e his score remains at 0 points).

You are given a binary array A1,A2,…,AN of length N, where Ai=1 denotes Chef's code passed the ith test case, Ai=0 denotes otherwise. You are also given the two integers M,K. Can you find how many points does Chef get?

Input Format
First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contains three space-separated integers N,M,K.
The second line contains N space-separated integer A1,A2,…,AN.
Output Format
For each testcase, output in a single line the score of Chef.

Constraints
1≤T≤100
2≤N≤100
1≤M<N
1≤K<100
0≤Ai≤1
Sample Input 1 
4
4 2 50
1 0 1 1
3 2 50
1 1 0
4 2 50
1 1 1 1
5 3 30
1 1 0 1 1
Sample Output 1 
0
50
100
0

*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,m,k,i;
	cin>>t;
	while(t--)
	{
	    int c=0,p=0;
	    cin>>n;
	    cin>>m;
	    cin>>k;
	    int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<n;i++)
	    {
	        if(a[i]==1)
	        c++;
	    }
	    if(c==n)
	    cout<<"100\n";
	    else
	    {   for(i=0;i<m;i++)
	        {
	            if(a[i]==1)
	            p++;
	            
	        }
	        if(p==m)
	        cout<<k<<"\n";
	        else
	        cout<<"0\n";
	    }
	   
	}
	return 0;
}
