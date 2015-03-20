#include<iostream>
using namespace std;
int main(){
    int cl,a[1000],b[1000],c[1000],pc=0;
    while(scanf("%d",&cl)&&cl!=0)
    {
                                 pc++;
                                 printf("Game %d:\n",pc);
                                 for(int i=0;i<cl;i++)scanf("%d",&c[i]);
                                 while(1)
                                 {
                                         for(int i=0;i<cl;i++)a[i]=c[i];
                                         int ac=0,bc=0;
                                         bool azero=true;
                                         for(int i=0;i<cl;i++){scanf("%d",&b[i]); if(b[i]!=0)azero=false; if(a[i]==b[i]){ac++;a[i]=10;b[i]=11;}}
                                         if(azero)break;
                                         for(int i=0;i<cl;i++)
                                         {
                                                 for(int j=0;j<cl;j++){if(a[i]==b[j]){bc++;a[i]=10;b[j]=11;}}
                                         }
                                         printf("    (%d,%d)\n",ac,bc);
                                 }
    }
    return 0;
}
