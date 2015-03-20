#include <iostream>
#include <math.h>

using namespace std;

string s,sa[100000],ns;
int fact[650],fc=0,slen,c,t;
bool r=false;

int main(){
    getline(cin,s);
    slen=s.length();
    t=sqrt(slen);
    for(int i=1;i<=t;i++)
        if(slen%i==0){
            fact[fc++]=i;
            if(i*i<slen) fact[fc++]=slen/i;
        }
    sort(fact,fact+fc);
    for(int i=0;i<fc;i++)
    {
        c=0;
        for(int j=0;j<slen;j+=fact[i],c++)
            sa[c]=s.substr(j,fact[i]);
        sort(sa,sa+c);
        ns="";
        for(int j=0;j<c;j++)
            ns+=sa[j];
        if(s!=ns){ cout<<ns<<endl; r=true; }
    }
    if(!r) printf("bomb!");
    return 0;
}