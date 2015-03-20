#include<iostream>
using namespace std;
int pas[28][29],tc,t[28],tct,n;
long long int ct;
int main(){
    pas[0][0]=pas[0][1]=1;
    for(int i=1;i<28;i++)
    {
            pas[i][0]=pas[i][i]=1;
            for(int j=1;j<i;j++)
                    pas[i][j]=pas[i-1][j]+pas[i-1][j-1];
            pas[i][i+1]=pas[i-1][i]*2;
    }
    for(int i=1;i<28;i++)pas[i][1]++;
    while(scanf("%d",&n)==1)
    {
         ct=tc=tct=0;
         while(n!=0)
         {
                    t[tc++]=n%2;
                    n/=2;
         }
         for(int i=tc-1;i>=0;i--)
         {
                 if(t[i]){
                          ct+=pas[i][i+1]*tct;
                          ct%=1000000000;
                          if(i==0)ct++;
                          else
                              for(int j=1;j<=i;j++)
                                      ct+=pas[i][j]*j;
                          tct++;
                 }
         }
         printf("%lld\n",ct);
    }
    return 0;
}
