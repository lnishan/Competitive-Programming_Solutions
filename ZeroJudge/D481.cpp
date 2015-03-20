#include<iostream>
using namespace std;
int main(){
    int a[100][100],b[100][100],r1,c1,r2,c2;
    while(scanf("%d%d%d%d",&r1,&c1,&r2,&c2)!=EOF)
    {
         if(c1!=r2)
                   printf("Error\n");
         else
         {
             for(int i=0;i<r1;i++)
                     for(int j=0;j<c1;j++)
                             scanf("%d",&a[i][j]);
             for(int i=0;i<r2;i++)
                     for(int j=0;j<c2;j++)
                             scanf("%d",&b[i][j]);
             for(int i=0;i<r1;i++)
             {
                     for(int j=0;j<c2;j++)
                     {
                             int tc=0;
                             for(int k=0;k<c1;k++)tc+=(a[i][k]*b[k][j]);
                             if(j!=0)printf(" ");
                             printf("%d",tc);
                     }
                     printf("\n");
             }
         }
    }
    return 0;
}
