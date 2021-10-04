#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    char temp;
    int size=w.length();
    int smallIndex=size-1, flag=1;

    if(w[size-2]<w[size-1]){
        temp=w[size-2];
        w[size-2]=w[size-1];
        w[size-1]=temp;
        flag=0;
    }
    
    else{
        smallIndex= (size-1)<(size-2)? (size-1): (size-2);
        for (int i = size-3; i >=0; i--)
        {
            if(w[i]<w[smallIndex]){
                temp=w[i];
                w[i]=w[smallIndex];
                w[smallIndex]=temp;
                flag=0;
                break;
            }
        }
    }

    if(flag){
        return "no answer";
    }
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

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
