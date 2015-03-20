#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string s;
int maxt,mint,a[26],n;
int main(){
    while(getline(cin,s))
    {
                         maxt=0;mint=100;
                         for(int i=0;i<26;i++)a[i]=0;
                         for(int i=0;i<s.length();i++)
                         {
                                                  a[s[i]-97]++;
                                                  if(a[s[i]-97]>maxt)maxt=a[s[i]-97];
                         }
                         for(int i=0;i<26;i++) if(a[i]!=0)mint=min(mint,a[i]);
                         n=maxt-mint;
                         bool chk=true;
                         for(int i=2;i<=sqrt(n);i+=2)
                         {
                                 if(n%i==0){chk=false; break;}
                                 if(i==2)i--;
                         }
                         if(n<2)chk=false;
                         cout<<((chk==true)?"Lucky Word":"No Answer")<<endl<<((chk==true)?n:0)<<endl;
    }
    return 0;
}
