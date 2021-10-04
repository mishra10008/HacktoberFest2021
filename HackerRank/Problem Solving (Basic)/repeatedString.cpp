#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */


long repeatedString(string s, long n) {

    // for each complete iteration of string
    int each=0, j=0;
    while(s[j]!='\0'){
        if(s[j]=='a'){
            each++;
        }
        j++;
    }

    long count=0;
    int len=s.length(), i=0;

    // for last incomplete iteration
    int last=n%len, lastCount=0;
    while(i<last){
        if(s[i]=='a'){
            lastCount++;
        }
        i++;
    }

    //  count= for each complete iteration + last incomplete iteration
    count+=(n/len*each)+lastCount;
    return count;    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
