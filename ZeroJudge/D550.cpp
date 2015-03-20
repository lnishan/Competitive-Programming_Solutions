#include<iostream>
using namespace std;
int n,m;
struct dat{
       int ar[200];
};
dat d[10000];
int input();
int input(){
    char c;int x;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
bool cmp(dat a,dat b);
bool cmp(dat a,dat b){
     for(int i=0;i<m;i++)
             if(a.ar[i]!=b.ar[i])return (a.ar[i]<b.ar[i]);
     return 0;
}
int main(){
    n=input();m=input();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) d[i].ar[j]=input();
    sort(d,d+n,cmp);
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            {
                    if(j!=0)printf(" ");
                    printf("%d",d[i].ar[j]);
            }
            putchar('\n');
    }
    return 0;
}
