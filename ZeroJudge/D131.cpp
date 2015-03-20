#include<iostream>
using namespace std;
int a[101][26],p[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},ti,n;
int main(){
    memset(a,0,sizeof(a));
    a[1][0]=0;
    for(int i=2;i<=100;i++)
    {
            ti=i;
            for(int j=1;j<=a[i-1][0];j++)a[i][j]=a[i-1][j];
            for(int j=1;j<=25;j++)
            {
                    if(ti%p[j]==0)
                    {
                         while(ti%p[j]==0){ti/=p[j];a[i][j]++;}
                         a[i][0]=j;
                    }
                    if(ti==1){a[i][0]=max(a[i-1][0],a[i][0]);break;}
            }
    }
    while(scanf("%d",&n)&&n!=0)
    {
         printf("%3d! =",n);
         for(int i=1;i<=a[n][0];i++)
         {
                 printf("%3d",a[n][i]);
                 if(i==15&&a[n][0]>15)putchar('\n');
         }
         putchar('\n');
    }
    return 0;
}
