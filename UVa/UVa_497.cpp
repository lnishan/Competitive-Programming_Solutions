#include<iostream>
#include<ctype.h>

using namespace std;

int t,a[1001],ac,dp[1001][2],maxh,maxi,path[1001],pc,pos;
bool newline;

int input(){
    char c;
    for(c=getchar();!isdigit(c);c=getchar()) if(c=='\n'){newline=true; return 0;};
    int x=c-48;
    for(c=getchar();isdigit(c);c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    //freopen("497.in","r",stdin);
    scanf("%d\n",&t);
    for(int d=0;d<t;d++)
    {
        ac=0;
        if(d<t-1){
            newline=false;
            while(!newline)
                a[++ac]=input();
        }else
            while(scanf("%d",&a[++ac])==1);
        memset(dp,0,sizeof(dp));
        maxh=a[0]=0;
        dp[0][0]=0;
        for(int i=1;i<ac;i++)
            for(int j=0;j<i;j++)
                if(a[i]>a[j] && dp[j][0]+1>dp[i][0]){
                    dp[i][0]=dp[j][0]+1;
                    dp[i][1]=j;
                    if(dp[i][0]>maxh){
                        maxh=dp[i][0];
                        maxi=i;
                    }
                }
        if(ac<=1)
            printf("Max hits: 0\n");
        else{
            pos=dp[maxi][1];
            path[0]=a[maxi]; pc=1;
            for(int i=1;i<dp[maxi][0];i++)
            {
                path[pc++]=a[pos];
                pos=dp[pos][1];
            }
            printf("Max hits: %d\n",maxh);
            for(int i=pc-1;i>=0;i--)
            {
                printf("%d",path[i]);
                if(i>0 || d<t-1) putchar('\n');
            }
        }
        putchar('\n');
    }
    while(1);
    return 0;
}
