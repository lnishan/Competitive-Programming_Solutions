#include<iostream>
#include<string>
using namespace std;
string bTimes(string n1,string n2);
string bTimes(string n1,string n2){
       int nsl=n1.length(),lsl=n2.length(),p,tn,zpos;
       string c(nsl+lsl,'0');
       for(int i=nsl-1;i>=0;i--)
       {
               for(int j=lsl-1;j>=0;j--)
               {
                       tn=(n1[i]-48)*(n2[j]-48)+c[i+j+1]-48;
                       c[i+j]+=tn/10;
                       c[i+j+1]=48+tn%10;
               }
       }
       if(c[0]=='0'){for(int i=1;;i++)if(c[i]!='0'){zpos=i;break;} c=c.substr(zpos,c.length()-zpos);}
       return c;
}
int main(){
    string s1,s2;
    while(getline(cin,s1))
    {
                          getline(cin,s2);
                          if(s1=="0"||s2=="0")printf("0\n");else cout<<bTimes(s1,s2)<<endl; 
    }
    return 0;
}
