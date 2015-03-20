#include<iostream>
#include<string>
using namespace std;
long long a[10001];
string s;
int main(){
    a[0]=a[1]=1;
    while(getline(cin,s) && s!="0")
    {
                         for(int i=1;i<s.length();i++)
                                 if((s[i-1]-48)*10+(s[i]-48)<=26 && (s[i]!='0' || s[i-1]!='0')) a[i+1]=a[i]+a[i-1]; else a[i+1]=a[i];
                         cout<<a[s.length()]<<endl;
    }
    return 0;
}
