#include<iostream>
#include<math.h>
using namespace std;
char c;
bool a[32768];
int p[3600],pct=0;
int main(){
    a[2]=true;
    for(int i=3;i<32768;i++) if(i%2)a[i]=true;else a[i]=false;
    for(int i=3;i<=181;i++)
            if(a[i])
                    for(int j=2;j<=32768/i;j++) a[i*j]=false;
    for(int i=2;i<=32768;i++)if(a[i]){p[pct]=i;pct++;}
    while(1)
    {
            int a,b,flag=0,tmp,no=1;
            bool datEx=false;
            while(1)
            {
                    bool ex=false;
                    while((c=getchar())==' '||c=='\n') if(c=='\n')ex=true;
                    if(ex)break;
                    int x=c-48;
                    while((c=getchar())!=' '&&c!='\n') x=x*10+c-48;
                    if(x==0){datEx=true;break;}
                    if(flag){b=x;for(int i=0;i<b;i++)no*=a;}else a=x;
                    flag=1-flag;
                    if(c=='\n')break;
            }
            if(datEx)break;
            no--;
            for(int i=pct-1;i>=0;i--)
            {
                    if(no%p[i]==0)
                    {
                                 int tmp=0;
                                 while(no%p[i]==0){no/=p[i];tmp++;}
                                 printf(" %d %d",p[i],tmp);
                    }
            }
            putchar('\n');
    }
    return 0;
}
