#include <iostream>

using namespace std;

int i,j,n,n1,n2,dp[30001],t,ans;
struct data{
    int sml,big;
};
data a[30001];

bool cmp(data a,data b){
    return a.big<b.big;
}

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            n1=input(); n2=input();
            a[i].big=max(n1,n2);
            a[i].sml=min(n1,n2);
        }
        a[0].big=a[0].sml=-1;
        sort(a,a+i,cmp);
        dp[0]=0; ans=0;
        for(i=1;i<=n;i++)
        {
            t=dp[0];
            for(j=0;j<i;j++)
                if(a[i].sml>=a[j].sml)
                    t=max(t,dp[j]);
            dp[i]=t+1;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
