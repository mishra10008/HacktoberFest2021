#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
        int marks[5];
        int total=0;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cin>>n;

    Student s[n];

    int counter=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>s[i].marks[j];
            s[i].total+=s[i].marks[j];
        }
        if(i){
            if(s[i].total > s[0].total)
                counter++;
        }
    }
    
    cout<<counter;
    
    return 0;
}
