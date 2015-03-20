#include<iostream>
#include<string>
using namespace std;
string bPlus(string s1,string s2);
int count,pos;
string s,n1,n2;
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
               if(nno>0)::count++;
               tn-=nno*10;
               c=tn+48;
               f=c+f;
       }
       if(nno!=0){c=nno+48; f=c+f;}
       return f;
}
int main(){
    while(getline(cin,s)&&s!="0 0")
    {
                         ::count=0;
                         pos=s.find(" ");
                         n1=s.substr(0,pos);
                         n2=s.substr(pos+1,s.length()-pos-1);
                         bPlus(n1,n2);
                         if(::count==0)cout<<"No carry operation."<<endl; else cout<<::count<<" carry operation"<<((::count>1)?"s":"")<<"."<<endl;
    }
    return 0;
}
