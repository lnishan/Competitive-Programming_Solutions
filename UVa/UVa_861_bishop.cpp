#include <iostream>

using namespace std;

const int S=8;
long long int a[S][S*S+1], sum;

int main(){
    int i, j, n, k, tmp[S*S+1];
    memset(a,0,sizeof(a));
    for(i=0; i<S; i++)
        a[i][0]=1;
    a[1][1]=2;
    a[2][1]=4; a[2][2]=2;
    for(i=3; i<S; i++)
        for(j=1; j<=i; j++)
        {
            a[i][j]=a[i-2][j]+a[i-2][j-1]*(i-j+1)*2;
            if( j>1 ) a[i][j]+=a[i-2][j-2]*(i-j+2)*(i-j+1);
        }
    while( scanf("%d%d", &n, &k)==2 && (n!=0 || k!=0) )
    {
        if( n==1 && k<2 )
            puts("1");
        else{
            sum=0;
            if( n%2 ){
                tmp[0]=1;
                for(j=1; j<=k; j++)
                    tmp[j]=a[n-2][j]+a[n-2][j-1]*(n-j+1);
                for(j=0; j<=k; j++)
                {
                    tmp[j]*=a[n-1][k-j];
                    sum+=tmp[j];
                }
            }else{
                for(j=0; j<=k; j++)
                    sum+=a[n-1][j]*a[n-1][k-j];
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}