#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

//  code to escape Timeout
int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r=start_up();

/*Write the class AddElements here*/
template <typename T>
class AddElements{
    public:
        T element1;
        T add(T ele2){
            return (element1+ele2);
        }
        AddElements(T ele1){
            element1=ele1;
        }
};
 template <>
 class AddElements <string>{
     public:
        string str;
        AddElements(string s){
            str=s;
        }
        string concatenate(string s){
            return (str+s);
        }
        
 };



int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat(element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint(element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
