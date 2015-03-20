//Layer44 : 11E

#include<iostream>
using namespace std;
int main(){
    int fib[45],n,fpos;
    fib[0]=fib[1]=1;
    for(int i=2;i<45;i++)
            fib[i]=fib[i-1]+fib[i-2];
    while(scanf("%d",&n)==1)
    {
         for(int i=0;i<44;i++)
                 if(fib[i]<=n)fpos=i;else break;
         printf("%d %d\n",fib[fpos-1],fib[fpos]);
    }
    return 0;
}
