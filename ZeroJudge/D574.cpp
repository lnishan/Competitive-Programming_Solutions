#include<iostream>
#include<string>
using namespace std;
string cstr(int no);
string cstr(int no){
       string f;
       while(no!=0)
       {
              f=char(no%10+48)+f;
              no=(no-no%10)/10;
       }
       return f;
}
int main(){
    int n,tc=0,sl=0;
    scanf("%d",&n);
    char c=getchar(),pc='*';
    string s_org,s;
    for(int i=0;i<n;i++)
    {
            c=getchar();
            if(c!=pc&&sl!=0){s+=cstr(tc)+pc;tc=1;}else tc++;
            pc=c;
            s_org+=c;
            sl++;
    }
    s+=cstr(tc)+pc;
    if(s.length()>=sl)cout<<s_org;else cout<<s;
    return 0;
}
