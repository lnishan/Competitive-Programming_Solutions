#include <iostream>

using namespace std;

char a[1001][124];
int n;

void pl(int d,int i1,int i2){
    int i,t,lenM=max(a[i1][0],a[i2][0]);
    for(i=1;i<=lenM;i++)
    {
        a[d][i]+=a[i1][i]+a[i2][i];
        if(a[d][i]>9){
            a[d][i]%=10;
            a[d][i+1]++;
        }
    }
    a[d][0]=lenM+(a[d][lenM+1]>0);
}

int main(){
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<1002;i++) a[i][0]=1;
    a[1][1]=1; a[2][1]=1;
    for(i=3;i<1001;i++)
        pl(i,i-3,i-2);
    while(scanf("%d",&n)==1)
    {
        for(i=a[n][0];i>=1;i--) putchar(a[n][i]+48);
        putchar('\n');
    }
    return 0;
}