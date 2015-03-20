#include<iostream>
#include<string>
using namespace std;
string cstr(int no);
string cstr(int no){
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
int main(){
    int ar[20]={1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208,9474,54748,92727,93084,548834};
    int a,b,st;
    while(cin>>a>>b)
    {
                    st=20;
                    string s="";
                    for(int i=0;i<20;i++){ if(ar[i]>=a){st=i; break;} }
                    for(int i=st;i<20;i++) if(b>=ar[i])s+=(cstr(ar[i])+" "); else break;
                    cout << ((s=="")?"none":s.substr(0,s.length()-1)) << endl;
    }
    return 0;
}
