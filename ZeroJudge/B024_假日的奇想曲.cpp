#include<iostream>
using namespace std;
int a[10001],col[20000],n;
int main(){
    col[0]=1;
    for(int i=1;i<=10000;i++)
    {
            for(int j=1;j<=(i-1)*2;j++)
            {
                    col[j]+=col[j-1];
                    col[j]%=10000;
            }
            col[i*2]=col[i*2-1]=col[i*2-2];
            a[i]=col[i*2];
    }
    while(scanf("%d",&n),n!=0)
         if(n<8)
                printf("%d\n",a[n]);
         else
             printf("%0.4d\n",a[n]);
    return 0;
}
