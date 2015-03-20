#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
                          bool pw=false;
                          int c=0;
                          for(int i=0;i<s.length();i++){
                                  if(pw){
                                         if(!((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122))){
                                                        pw=false;
                                         }
                                  }else{
                                        if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)){
                                                     pw=true;
                                                     c++;
                                        }
                                  }
                          }
                          cout << c << endl;
    }
    return 0;
}
                                            
                                     
                                     
                                  
