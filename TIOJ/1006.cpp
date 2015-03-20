/* 2/2/2010 */
#include<iostream>
#include<string>
using namespace std;
string bMinus(string s1,string s2);
bool bNumCmp(string s1,string s2);
string bDivide(string s1,string s2);
string bDivide(string s1,string s2){
       string f,ts1,prevn;
       if(bNumCmp(s2,s1))
       {
                         f="00";
       }else{
            for(int i=0;i<=s1.length()-s2.length();i++)
            {
                    ts1=s1.substr(i,s2.length());
                    if(prevn!="0")ts1=prevn+ts1;
                    for(int i=1;;i++)
                    {
                            if(bNumCmp(s2,ts1)){f+=char(i-1+48);break;}
                            ts1=bMinus(ts1,s2);
                    }
                    int jscope=s2.length()-ts1.length();
                    for(int j=0;j<jscope;j++)ts1="0"+ts1;
                    s1.replace(i,s2.length(),ts1);
                    if(jscope==0)prevn=ts1.substr(0,1);else prevn="";
            }
       }
       if(f[0]=='0')f=f.substr(1,f.length()-1);
       return f;
}
string bMinus(string s1,string s2){
       string sl,ss,f;
       int nno=0,tn;
       sl=((bNumCmp(s1,s2))?s1:s2);
       ss=((s1==sl)?s2:s1);
       for(int i=0;i<sl.length();i++)
       {
               tn=(i<ss.length())?sl[sl.length()-i-1]-ss[ss.length()-i-1]+nno:sl[sl.length()-i-1]-48+nno;
               if(tn<0){tn+=10;nno=-1;}else{nno=0;}
               f=char(tn+48)+f;
       }
       for(int i=0;;i++){ if(f[i]!='0'){f=f.substr(i,f.length()-i);break;} }
       if(s1==s2)f="0";
       return f;
}
bool bNumCmp(string s1,string s2){
     bool rs=false;
     if(s1.length()>s2.length())
     {
         rs=true;
     }else if(s2.length()>s1.length())
     {
         rs=false;
     }else{
         for(int i=0;i<s1.length();i++){
                 if(s1[i]>s2[i]){rs=true;break;}else if(s1[i]<s2[i]){rs=false;break;}
         }
     }
     return rs;
}
int main(){
    string s1,s2;
    while(cin>>s1>>s2)
    cout<<bDivide(s1,s2)<<endl;
}
