#include<iostream>
#include<string>
#include<math.h>
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
    string s,ts,sl,sr;
    int n,n1,n2,lpos,rpos,puncp;
    scanf("%d",&n);getline(cin,s);
    for(int i=0;i<n;i++)
    {
            getline(cin,s);
            bool chk=true;
            while(1)
            {
                    rpos=s.find_first_of(")");
                    lpos=s.find_last_of("(",rpos);
                    ts=s.substr(lpos+1,rpos-lpos-1);
                    puncp=ts.find(",");
                    n1=atoi(ts.substr(0,puncp).c_str());
                    n2=atoi(ts.substr(puncp+1,ts.length()-puncp).c_str());
                    if(n1!=n2){chk=false;break;}
                    if(rpos==s.length()-1)break;
                    s=s.substr(0,lpos)+cstr(n1+n2)+s.substr(rpos+1,s.length()-rpos-1);
            }
            if(chk)printf("Yes\n");else printf("No\n");
    }
    return 0;
}
