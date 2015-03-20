#include<iostream>
using namespace std;
int main(){
    int r[501][501],a,b,n;
    for(int i=1;i<=500;i++)
    {
            for(int j=i+1;j<=500;j++)
            {
                    a=i;b=j;
                    while(a!=0&&b!=0)if(a>b)a%=b; else b%=a;
                    r[i][j]=((a==0)?b:a);
            }
    }
    while(scanf("%d",&n)&&n!=0)
    {
                              long int c=0;
                              for(int i=1;i<=n;i++)
                                      for(int j=i+1;j<=n;j++)
                                              c+=r[i][j];
                              printf("%d\n",c);
    }
    return 0;
}
