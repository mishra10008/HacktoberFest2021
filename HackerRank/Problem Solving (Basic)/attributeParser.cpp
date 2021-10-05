#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string temp;
	int n, q;
	cin>>n >>q;

	vector<string> hrml;
	vector<string> query;

	for (int i = 0; i < n; i++)
	{
        getline(cin, temp);
		hrml.push_back(temp);
	}

	for (int j = 0; j < q; j++)
	{
        getline(cin, temp);
		query.push_back(temp);
	}
	
    
	

	
	
    return 0;
}
