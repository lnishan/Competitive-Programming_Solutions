#include<iostream>
using namespace std;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    int n,bn,a[100],ct=0;
    bool sum[20001],chk;
    while(scanf("%d",&n)==1)
    {
         chk=true;
         bn=0;
         memset(sum,0,sizeof(sum));
         for(int i=0;i<n;i++)
         {
                 a[i]=input();
                 if(a[i]-bn<=0)chk=false;
                 bn=a[i];
         }
         if(chk)
                for(int i=0;i<n-1;i++)
                {
                        for(int j=i;j<n;j++)
                        {
                                if(sum[a[i]+a[j]])
                                {
                                 chk=false;
                                 break;
                                }else sum[a[i]+a[j]]=true;
                        }
                }
         if(chk)printf("Case #%d: It is a B2-Sequence.\n\n",++ct);else printf("Case #%d: It is not a B2-Sequence.\n\n",++ct);
    }
    return 0;
}
