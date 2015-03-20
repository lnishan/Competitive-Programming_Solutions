#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
                          int st=0;
                          for(int i=0;i<s.length();i++){
                                  if(s[i]!='0'){
                                              st=i;
                                              break;
                                  }
                          }
                          bool chk=false;
                          for(int i=s.length()-1;i>=st;i--){
                                  if(s[i]!='0' && chk==false)
                                               chk=true;
                                  if(chk==true) cout << s[i];
                          }
                          cout<<endl;
    }
    return 0;
}
