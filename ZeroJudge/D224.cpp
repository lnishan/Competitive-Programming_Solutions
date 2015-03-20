#include <iostream>

using namespace std;

unsigned long long int a[1000001];
int i,j,n;

int main(){
    for(i=0;i<1000001;i++) a[i]=1;
    for(i=0;i<2;i++)
        for(j=2;j<1000001;j++)
            a[j]+=a[j-2];
    while(scanf("%d",&n)==1)
        printf("%lld\n",a[n]);
    return 0;
}
