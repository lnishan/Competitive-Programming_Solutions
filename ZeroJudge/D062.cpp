#include<iostream>
using namespace std;
int main(){
    long long int a[35][35],c,b,h,pos;
    for(int i=0;i<35;i++){a[i][0]=1;for(int j=1;j<35;j++)a[i][j]=0;}
    for(int i=1;i<35;i++)
            for(int j=1;j<=i;j++)
                    a[i][j]=a[i-1][j]+a[i-1][j-1];
    while(scanf("%lld%lld%lld",&c,&b,&h)!=EOF)
    {
         pos=0;
         for(int i=1;i<35;i++)
                 if(a[i][i/2]==c){pos=i;break;}
         if(pos+1<b)b=(pos+1)/2;
         int r=0,st;
         if(pos%2==1)st=pos/2-(b-2)/2;else st=pos/2-(b-1)/2;
         for(int i=0;i<b;i++)
                 for(int j=st;j<=st+i;j++)
                         r+=a[pos-b+i+1][j];
         printf("%d\n",r);
    }
    return 0;
}
