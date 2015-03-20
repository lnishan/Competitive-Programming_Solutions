#include <iostream>

using namespace std;

int a[200][200],dp1[200][200],r,c,curmin,maxArea;

inline int input(){
    char ch;
    for(ch=getchar();ch<48||ch>57;ch=getchar()) ;
    return ch-48;
}

int main(){
    int i,j,k;
    while(scanf("%d%d",&r,&c)==2)
    {
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                a[i][j]=input();
        for(i=0;i<r;i++)
            dp1[i][c-1]=a[i][c-1];
        for(i=0;i<r;i++)
            for(j=c-2;j>=0;j--)
                if(a[i][j])
                    dp1[i][j]=dp1[i][j+1]+1;
                else
                    dp1[i][j]=0;
        maxArea=-1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(dp1[i][j]>0){
                    curmin=dp1[i][j];
                    maxArea=max(maxArea,curmin);
                    for(k=i+1;k<r;k++)
                    {
                        if(dp1[k][j]==0) break;
                        curmin=min(curmin,dp1[k][j]);
                        maxArea=max(maxArea,curmin*(k-i+1));
                    }
                }
        printf("%d\n",maxArea);
    }
    return 0;
}
