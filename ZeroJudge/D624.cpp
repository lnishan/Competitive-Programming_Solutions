#include<iostream>

using namespace std;

long long int a[17][91];
int n,m;

int main(){
    for(int m=1;m<=16;m++)
    {
        a[m][0]=1;
        for(int i=1;i<m,i<=90;i++) a[m][i]=a[m][i-1]*2;
        if(m<=90){
            a[m][m]=a[m][m-1]*2-1;
            for(int i=m+1;i<=90;i++) a[m][i]=a[m][i-1]*2-a[m][i-1-m];
        }
    }
    while(scanf("%d%d",&m,&n)==2)
        printf("%lld\n",a[m+1][n]);
    return 0;
}
