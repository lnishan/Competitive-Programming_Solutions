#include<iostream>
#include<string>
using namespace std;
string bPlus(string s1,string s2);
string bMinus(string s1,string s2);
string bTimes(string n1,string n2);
string bDivide(string s1,string s2);
bool bNumCmp(string s1,string s2);

string bPlus(string s1,string s2){
       string sl,ss,f="";
       int nno=0,tn;
       char c;
       sl=((s1.length()>s2.length())?s1:s2);
       ss=((s1==sl)?s2:s1);
       for(int i=0;i<sl.length();i++)
       {
               tn=(i<ss.length())?sl[sl.length()-i-1]+ss[ss.length()-i-1]-96+nno:sl[sl.length()-i-1]-48+nno;
               nno=tn/10;
               tn-=nno*10;
               c=tn+48;
               f=c+f;
       }
       if(nno!=0){c=nno+48; f=c+f;}
       return f;
}
string bMinus(string s1,string s2){
       string sl,ss,f;
       int nno=0,tn;
       char c;
       sl=((bNumCmp(s1,s2))?s1:s2);
       ss=((s1==sl)?s2:s1);
       for(int i=0;i<sl.length();i++)
       {
               tn=(i<ss.length())?sl[sl.length()-i-1]-ss[ss.length()-i-1]+nno:sl[sl.length()-i-1]-48+nno;
               if(tn<0){tn+=10;nno=-1;}else{nno=0;}
               c=tn+48;
               f=c+f;
       }
       for(int i=0;;i++){ if(f[i]!='0'){f=f.substr(i,f.length()-i);break;} }
       if(s1!=sl)f="-"+f;
       if(s1==s2)f="0";
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
string bDivide(string s1,string s2){
       string f,ts1,prevn;
       char c;
       if(bNumCmp(s2,s1))
       {
                         f="0";
       }else{
            for(int i=0;i<=s1.length()-s2.length();i++)
            {
                    ts1=prevn+s1.substr(i,s2.length());
                    if(bNumCmp(s2,ts1))
                    {
                                       if(i!=0)f+="0";
                                       prevn=ts1.substr(0,1);
                    }else{
                          for(int i=1;;i++)
                          {
                                  if(bNumCmp(s2,ts1)){c=i-1+48;f+=c;break;}
                                  ts1=bMinus(ts1,s2);
                          }
                          int jscope=s2.length()-ts1.length();
                          for(int j=0;j<jscope;j++)ts1="0"+ts1;
                          s1.replace(i,s2.length(),ts1);
                          if(jscope==0)prevn=ts1.substr(0,1);else prevn="";
                    }
            }
       }
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
    string s,n1,n2,ope,f;
    int spc1,spc2;
    while(getline(cin,s))
    {
                         spc1=s.find(" ",0);
                         spc2=s.find(" ",spc1+1);
                         n1=s.substr(0,spc1);
                         ope=s.substr(spc1+1,1);
                         n2=s.substr(spc2+1,s.length()-spc2-1);
                         if(ope=="+")
                                     f=bPlus(n1,n2);
                         else if(ope=="-")
                              f=bMinus(n1,n2);
                         else if(ope=="*")
                              f=bTimes(n1,n2);
                         else
                             f=bDivide(n1,n2);
                         cout<<f<<endl;
    }
    return 0;
}
