#include<iostream>
#include<string>
using namespace std;
string bTimes(string n1,string n2);
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
string bTimes(string n1,string n2){
       string sn=(n1.length()>n2.length())?n2:n1;
       string ln=(sn==n2)?n1:n2;
       int nsl=sn.length(),lsl=ln.length(),p,tn;
       string c(nsl+lsl,'0');
       for(int i=nsl-1;i>=0;i--)
       {
               for(int j=lsl-1;j>=0;j--)
               {
                       tn=(sn[i]-48)*(ln[j]-48)+c[i+j+1]-48;
                       c[i+j]+=tn/10;
                       c[i+j+1]=48+tn%10;
               }
       }
       if(c[0]=='0')c=c.substr(1,c.length()-1);
       return c;
}
int main(){
    string s[1001];s[1]="1";
    for(int i=2;i<=1000;i++)s[i]=bTimes(s[i-1],cstr(i));
    int n;
    while(scanf("%d",&n)!=EOF)cout<<n<<"!"<<endl<<s[n]<<endl;
    return 0;
}
