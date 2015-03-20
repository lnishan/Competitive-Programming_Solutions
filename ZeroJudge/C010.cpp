#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,ns=0,a[10000];
    while(scanf("%d",&n)!=EOF)
    {
                              int ind=-1;
                              for(int i=0;i<ns;i++) if(a[i]>n)ind=i;else break;
                              ind++;
                              for(int i=ns;i>ind;i--)a[i]=a[i-1];
                              a[ind]=n;
                              ns++;
                              if(ns%2==1)printf("%d\n",a[ns/2]);else printf("%d\n",(a[ns/2]+a[ns/2-1])/2);
    }
    return 0;
}
