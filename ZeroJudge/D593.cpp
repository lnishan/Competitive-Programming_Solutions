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
    string s;
    int n;
    cin>>n;
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
            getline(cin,s);
            int sum=0;
            for(int i=0;i<s.length();i++)sum+=(s[i]-48);
            s=cstr(sum);
            while(s.length()!=1)
            {
                                 int sum2=0;
                                 for(int i=0;i<s.length();i++)sum2+=(s[i]-48);
                                 s=cstr(sum2);
            }
            cout<<s<<", "<<((s=="2")?"Yes":"No")<<endl;
    }
    return 0;
}
