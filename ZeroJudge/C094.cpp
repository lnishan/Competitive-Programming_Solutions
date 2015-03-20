#include<iostream>
using namespace std;
int main(){
    int ct=0,n,m,c,a[20][2],ni;
    while(scanf("%d%d%d",&n,&m,&c)&&n!=0)
    {
         ct++;
         printf("Sequence %d\n",ct);
         for(int i=0;i<n;i++){scanf("%d",&a[i][0]);a[i][1]=0;}
         int cUse=0,maxCs=0;
         for(int i=0;i<m;i++)
         {
                 scanf("%d",&ni);ni-=1;
                 if(a[ni][1]){
                             cUse-=a[ni][0];a[ni][1]=0;}
                 else{
                      cUse+=a[ni][0];a[ni][1]=1;
                      if(cUse>maxCs)maxCs=cUse;}
         }
         if(maxCs>c)
                    printf("Fuse was blown.\n\n");
         else
                    printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",maxCs);
    }
    return 0;
}
