#include<iostream>
using namespace std;
int main(){
    long long int a[51];
    a[0]=a[1]=1;
    for(int i=2;i<51;i++)a[i]=a[i-1]+a[i-2];
    int n;
    while(scanf("%d",&n) && n!=0)printf("%lld\n",a[n]);
    return 0;
}
