// 序列長度問題(Sequence)
#include<iostream>
using namespace std;
string smallTimes(int a[],int alen,int n);
string bPlus(string s1,string s2);
string bPlus(string s1,string s2){
       string f,sl=((s1.length()>s2.length())?s1:s2),ss=((s1==sl)?s2:s1);
       int nno=0,tn;
       for(int i=0;i<sl.length();i++)
       {
               tn=(i<ss.length())?sl[sl.length()-i-1]+ss[ss.length()-i-1]-96+nno:sl[sl.length()-i-1]-48+nno;
               nno=tn/10;
               tn-=nno*10;
               f=char(tn+48)+f;
       }
       if(nno!=0)f=char(nno+48)+f;
       return f;
}
string smallTimes(string a,int n){
    string s;
    int tn,prevn=0;
    for(int i=a.length()-1;i>=0;i--)
    {
            tn=(a[i]-48)*n+prevn;
            s=char(tn%10+48)+s;
            prevn=tn/10;
    }
    if(prevn!=0)
                while(prevn!=0){s=char(prevn%10+48)+s;prevn/=10;}
    return s;
}
int main(){
     int n;
     while(scanf("%d",&n)!=EOF)
     {
      string stot="0",stm="1";
      for(int i=n;i>=1;i--)
      {
              stm=smallTimes(stm,i);
              stot=bPlus(stot,smallTimes(stm,n-i+1));
      }
      cout<<stot<<endl;
     }
     return 0;
}
