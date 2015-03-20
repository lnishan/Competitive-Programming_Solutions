#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    bool l=false;
    while(getline(cin,s))
    {
                         string sf="";
                         for(int i=0;i<s.length();i++)
                         {
                                 if(s[i]==34){
                                     if(l==false)
                                     {sf+="``";l=true;}
                                     else
                                     {sf+="''";l=false;}
                                 }else{
                                       sf+=s[i];
                                 }
                         }
                         cout << sf << endl;
    }
    return 0;
}
