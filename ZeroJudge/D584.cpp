#include<iostream>
using namespace std;
int main(){
    int a,b,pt,m;
    while(scanf("%d%d",&a,&b)==2)
    {
         m=(a==2)?8:10;
         if(a==0||b<m)
             putchar('0');
         else{
             pt=(b-m)*3;
             if(b>=120)pt+=6;
             else if(b>=70)pt+=3;
             else if(b>=30)pt+=2;
             else pt++;
             printf("%d",pt);
         }
         putchar('\n');
    }
    return 0;
}
