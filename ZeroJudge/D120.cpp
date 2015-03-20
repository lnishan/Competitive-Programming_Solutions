#include<iostream>
using namespace std;
bool p[1000001];
int pr[100000];
int main(){
    int pc=0,n;
    p[1]=false;p[2]=true;
    for(int i=3;i<=1000000;i++)if(i%2==0)p[i]=false;else p[i]=true;
    for(int i=3;i<=1000;i++)
            if(p[i])
                    for(int j=i+i;j<=1000000;j+=i)p[j]=false;
    for(int i=2;i<=1000000;i++)
            if(p[i])
            {
                    pr[pc]=i;
                    pc++;
            }
    while(scanf("%d",&n)&&n!=0)
    {
         int prc=0;
         for(int i=0;i<pc;i++)
         {
                 if(pr[i]>n)break;
                 if(n%pr[i]==0)prc++;
         }
         printf("%d : %d\n",n,prc);
    }
    return 0;
}
