#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main(){
    string s;
    while(cin>>s && s!="0"){
                  int c=0;
                  for(int i=0;i<s.length();i++){
                          if(isalpha(s[i])){
                                           c+=(toupper(s[i])-64);
                          }else{
                                           c=-1;
                                           break;
                          }
                  }
                  if(c==-1)
                           cout << "Fail" << endl;
                  else
                           cout << c << endl;
    }
    return 0;
}
