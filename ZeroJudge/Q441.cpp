#include<iostream>
using namespace std;
int ns,n[13];
void DFS(int ind,int a[],int ac){
     a[ac++]=n[ind];
     if(ac==6){
          for(int i=0;i<6;i++)
          {
                  if(i!=0)putchar(' ');
                  printf("%d",a[i]);
          }
          putchar('\n');
     }else
          for(int i=ind+1;i<=ns-(6-ac);i++)DFS(i,a,ac);
}
int main(){
    int a[13];
    while(scanf("%d",&ns) && ns!=0)
    {
         for(int i=0;i<ns;i++)scanf("%d",&n[i]);
         for(int i=0;i<ns;i++)
                 if(ns-i>=6)DFS(i,a,0);else break;
         putchar('\n');
    }
    return 0;
}
