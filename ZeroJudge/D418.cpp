#include<iostream>
#include<string>
using namespace std;
int main(){
    int ds,n,a[35],ac;   // n=1 Special Case
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            ac=0;
            scanf("%d",&n);
            for(int j=9;j>1;j--)
            {
                    if(n%j==0)
                    {
                         while(n%j==0)
                         {
                              a[ac]=j;
                              ac++;
                              n/=j;
                         }
                    }
            }
            if(n==1 && ac==0)putchar('1');
            else if(n==1) for(int j=ac-1;j>=0;j--)putchar(a[j]+48);
            else printf("-1");
            putchar('\n');
    }
    return 0;
}
