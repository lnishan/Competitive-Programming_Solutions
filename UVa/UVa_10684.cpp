#include<iostream>
using namespace std;
int main(){
    int n,maxn,minn,a,ct;
    while(scanf("%d",&n)&&n!=0)
    {
         scanf("%d",&maxn);
         ct=maxn;
         minn=0;
         for(int i=1;i<n;i++)
         {
                 minn=min(minn,ct);
                 scanf("%d",&a);
                 ct+=a;
                 maxn=max(maxn,ct-minn);
         }
         if(maxn>0)printf("The maximum winning streak is %d.\n",maxn);else printf("Losing streak.\n");
    }
    return 0;
}
