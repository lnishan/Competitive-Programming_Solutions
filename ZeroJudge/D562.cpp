#include<iostream>
#include<string>
using namespace std;
int input();
int main(){
    int n,a[100],pos;
    char c;
    string s;
    while(scanf("%d",&n)!=EOF)
    {
                              for(int i=0;i<n;i++)a[i]=input();
                              bool dir=true;int tpos=0;
                              for(int i=n-1;i>=0;i--)
                              {
                                      s="";
                                      for(int j=tpos;j<=i+tpos;j++)
                                      {
                                              if(dir)pos=j;else pos=n-1-j;
                                              if(j!=tpos)s+=" ";
                                              c=a[pos]/10+48;
                                              if(c!=0)s+=c;
                                              c=a[pos]%10+48;
                                              s+=c;
                                      }
                                      cout<<s<<endl;
                                      if(dir==false)tpos++;
                                      if(dir)dir=false;else dir=true;
                              }
    }
    return 0;
}
int input(){
    char c;int x;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
