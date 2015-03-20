#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(){
    string s;
    char cha[1];
    while(getline(cin,s)){
                          int c=0;
                          for(int i=0;i<s.length();i++){
                                  if(s[i] != '-'){
                                               cha[0]=s[i];
                                               c+=atoi(cha);
                                  }
                          }
                          cout << ((c%3==0)?"yes":"no") << endl;
    }
    return 0;
}
