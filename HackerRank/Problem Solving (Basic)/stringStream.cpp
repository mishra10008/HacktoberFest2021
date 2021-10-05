#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string str;
    getline(cin, str);
    stringstream ss(str);

    char c;
    int val;

    while(1){
        ss>>val>>c;
        cout<<val <<endl;
        if(!c){
            break;
        }
        c=NULL;
    }

    
    return 0;
}
