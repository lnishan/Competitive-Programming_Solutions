#include<iostream>
using namespace std;
int ns,teamno,teamps,n,askn,p[100001];
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    while(scanf("%d",&ns)==1)
    {
         for(int i=0;i<ns;i++)
         {
                 teamno=input();
                 teamps=input();
                 for(int i=0;i<teamps;i++)
                 {
                         n=input();
                         p[n]=teamno;
                 }
         }
         askn=input();
         printf("%d\n",p[askn]);
    }
    return 0;
}
