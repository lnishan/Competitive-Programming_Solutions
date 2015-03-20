#include<iostream>
#include<string>
using namespace std;
string siTimes(string scal, int ncal);
string bPlus(string s1,string s2);
int main(){
    int n;
    string a[1001];
    a[1]="1";
    for(int i=2;i<=1000;i++)a[i]=siTimes(a[i-1],2);
    for(int i=2;i<=1000;i++)a[i]=bPlus(a[i],a[i-1]);
    while(cin>>n)
                    cout<<a[n]<<endl;
    return 0;
}
string siTimes(string scal, int ncal){
       int prevn=0,tn;
       for(int i=scal.length()-1;i>=0;i--)
       {
               tn=(scal[i]-48)*ncal + prevn;
               prevn=tn/10;
               scal[i]=48+ tn-prevn*10;
       }
       char cha=48+prevn;
       if(prevn!=0) scal=cha+scal;
       return scal;
}
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
