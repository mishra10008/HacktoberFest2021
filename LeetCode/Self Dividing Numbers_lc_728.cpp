// 728. Self Dividing Numbers
// Easy

// 846

// 315

// Add to List

// Share
// A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

// Also, a self-dividing number is not allowed to contain the digit zero.

// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

// Example 1:
// Input: 
// left = 1, right = 22
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// Note:

// The boundaries of each input argument are 1 <= left <= right <= 10000.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dividing(int i)
    {
        int sum=0;
       while(i)
            { 
                int ld=i%10;
                if(i%ld==0)
                sum+=0;
                else sum+=1;
                i/=10;

            }
        // if(sum!=0)  return 0;
    return sum;
        
    }
    void selfDividingNumbers(int left, int right) 
    {
        vector<int> output;
        for(int i=left;i<=right;i++)
        {
            if output.push_back(i) ;
      
        }
        for(auto i: output) cout<<i;
    }
         
};
int main()
{
    int left =1,right=22;
    Solution solution;
    solution.selfDividingNumbers(left,right);
    
}