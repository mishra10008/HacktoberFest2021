
/*
709. To Lower Case
Easy

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"

Example 2:

Input: s = "here"
Output: "here"

Example 3:

Input: s = "LOVELY"
Output: "lovely"

 

Constraints:

    1 <= s.length <= 100
    s consists of printable ASCII characters.

Accepted
297,573
Submissions
368,786
*/
class Solution
{
public:
    string toLowerCase(string s)
    {
        string out;
        for (auto i : s)
        {
            if (i >= 'A' && i <= 'Z')
                out += (i + 32); //uper to lower by adding 32
            else
                out += i;
        }
        return out;
    }
};