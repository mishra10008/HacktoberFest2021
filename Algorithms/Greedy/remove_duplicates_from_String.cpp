#include <bits/stdc++.h>

using namespace std;

char *removeduplicates(char str[], int n) {
    int index = 0;
    for (int i = 0; i<n;i++) {
        int j;
        for (j = 0; j<i;j++) {
            if (str[i] == str[j]) 
                break;
        }
        if (j == i) 
            str[index++] = str[i];
    }
    return str;
}

int main()
{
    char str[100];
    cin>>str;
    int n = sizeof(str)/sizeof(str[0]);
    cout<<removeduplicates(str,n);
    return 0;
}