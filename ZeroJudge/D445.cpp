#include<iostream>

using namespace std;

int sum=1,a[1000],rep[1000][2],repc,p[40],n;

int main(){
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    a[1]=1;
    for(int i=2;i<40;i++)
    {
        repc=0;
        for(int j=1;j<=sum;j++)
            if(a[j]>0 && j+i<1000){
                rep[repc][0]=j+i;
                rep[repc++][1]=a[j];
            }
        for(int j=0;j<repc;j++)
            a[rep[j][0]]+=rep[j][1];
        sum+=i;
        if(sum%2==0) p[i]=a[sum/2];
    }
    while(scanf("%d",&n)==1)
        printf("%d\n",p[n]);
    return 0;
}
