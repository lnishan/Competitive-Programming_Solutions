#include<iostream>
using namespace std;
int sum[100][100];
int main(){
    int n,area,maxarea;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)sum[i][j]=0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        scanf("%d",&sum[i][j]);
                        if(i==0&&j==0)
                             maxarea=sum[0][0];
                        else if(i==0)
                             sum[0][j]+=sum[0][j-1];
                        else if(j==0)
                             sum[i][0]+=sum[i-1][0];
                        else
                             sum[i][j]+=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]);
                        maxarea=max(maxarea,sum[i][j]);
                        for(int k=0;k<i;k++)maxarea=max(maxarea,sum[i][j]-sum[k][j]);
                        for(int l=0;l<j;l++)maxarea=max(maxarea,sum[i][j]-sum[i][l]);
                        for(int k=0;k<i;k++)
                                for(int l=0;l<j;l++)
                                        maxarea=max(maxarea,sum[i][j]-sum[i][l]-sum[k][j]+sum[k][l]);
                }
        }
        printf("%d\n",maxarea);
    }
    return 0;
}
