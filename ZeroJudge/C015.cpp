#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
using namespace std;

string cstr(long long int no);
bool rev(string s);
string cstr(long long int no){
       string f="";
       char c;
       while(no!=0)
       {
              c=(no%10+48);
              f=c+f;
              no=(no-no%10)/10;
       }
       return f;
}
bool rev(string s){
       bool chk=true;
       for(int i=0;i<s.length()/2;i++){ if(s[i]!=s[s.length()-i-1]){chk=false;break;} }
       return chk;
}
int n,c;
long long int n1,n2;
string s,s2;
int main(){
    cin>>n;
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
            c=0;
            getline(cin,s);
            do
            {
                                n1=atoi(s.c_str());
                                s2="";
                                for(int j=0;j<s.length();j++)s2=s[j]+s2;
                                n2=atoi(s2.c_str());
                                s=cstr(n1+n2);
                                c++;
            }while(rev(s)==false);
            cout<<c<<" "<<s<<endl;
    }
    return 0;
}
