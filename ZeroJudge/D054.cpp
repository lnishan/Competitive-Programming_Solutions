#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int ds,n;
    long long int a[41];
    a[0]=a[1]=1;
    for(int i=2;i<41;i++)
    {
            a[i]=(a[i-1]+a[i-2])*2;
            if(i%2)a[i]--;else a[i]++;
    }
    scanf("%d",&ds);
    for(int i=0;i<ds;i++){scanf("%d",&n);printf("%lld\n",a[n]);}
    return 0;
}
