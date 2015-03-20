#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main(){
    string s, a="";
    for(int i=0;i<1376;i++){
                          getline(cin,s);
                          for(int i=0;i<s.length();i++){
                                  if( isalpha(s[i]) ) a+=s[i];
                          }
    }
    cout << a;
    return 0;
}
