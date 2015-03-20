#include<iostream>
using namespace std;
int main(){
    int a[9];
    while(scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8])!=EOF)
    {
         bool st=false,az=true;
         for(int i=0;i<9;i++)
         {
                 if(a[i]!=0)az=false;
                 if(a[i]!=0){
                            if(st){
                                  if(a[i]<0)printf(" - ");else printf(" + ");
                                  if((a[i]!=1&&a[i]!=-1)||i==8)printf("%d",(a[i]>0)?a[i]:-a[i]);
                                  if(i==7)printf("x");else if(i!=8)printf("x^%d",8-i);
                            }else{
                                  if((a[i]!=1&&a[i]!=-1)||i==8)printf("%d",a[i]);else if(a[i]==-1)printf("-");
                                  if(i==7)printf("x");else if(i!=8)printf("x^%d",8-i);
                                  st=true;
                            }
                 }
         }
         if(az)printf("0");
         putchar('\n');
    }
    return 0;
}
