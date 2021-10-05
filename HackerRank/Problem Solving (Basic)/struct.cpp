#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Student sample;
    cin>>sample.age;  
    cin>>sample.first_name;  
    cin>>sample.last_name;  
    cin>>sample.standard;  

    cout<<sample.age <<" " <<sample.first_name <<" " <<sample.last_name <<" " <<sample.standard;
    
    return 0;
}
