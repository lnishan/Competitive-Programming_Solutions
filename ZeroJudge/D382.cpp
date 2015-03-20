#include<iostream>
using namespace std;
int n,m,t,ix,iy,ax,ay;
short a[10001][1001];
bool y;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    while(scanf("%d%d",&n,&m)==2)
    {
         for(int i=1;i<=n;i++)
                 a[i][0]=0;
         for(int i=0;i<m;i++)
         {
                 ix=input();
                 iy=input();
                 a[ix][++a[ix][0]]=iy;
         }
         t=input();
         for(int i=0;i<t;i++)
         {
                 ax=input();
                 ay=input();
                 y=false;
                 for(int j=1;j<=a[ax][0];j++)
                         if(a[ax][j]==ay){y=true;break;}
                 if(y)printf("Yes\n");else printf("No\n");
         }
    }
    return 0;
}
