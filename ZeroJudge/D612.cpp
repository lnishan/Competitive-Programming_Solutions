#include<iostream>
using namespace std;
int m[20];long long int ways[1000001],n;
int main(){
    m[0]=1;
    for(int i=1;i<20;i++)m[i]=m[i-1]*2;
    memset(ways,0,1000001);
    ways[0]=1;
    for(int i=0;i<20;i++)
            for(int j=m[i];j<=1000000;j++)
                    ways[j]=(ways[j]+ways[j-m[i]])%1000000000;
    scanf("%d",&n);
    printf("%lld",ways[n]);
    return 0;
}
