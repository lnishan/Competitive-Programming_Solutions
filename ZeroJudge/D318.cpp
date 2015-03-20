#include<iostream>
using namespace std;
int main(){
    int three[20],a,n;
    three[0]=1;
    for(int i=1;i<20;i++) three[i]=three[i-1]*3;
    while(scanf("%d",&a)&&a>=0)
    {
         for(int i=1;;i++)
                 if(three[i]>a){n=i-1;break;}
         for(int i=n;i>=0;i--)
         {
                 putchar(a/three[i]+48);
                 a%=three[i];
         }
         putchar('\n');
    }
    return 0;
}
