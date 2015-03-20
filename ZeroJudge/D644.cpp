// 第300055天 a[300054]=1; 第300056天 a[300055]=1;
#include <iostream>

using namespace std;

int a[300054],n;

int main(){
    a[0]=a[1]=1;
    for(int i=2;i<300054;i++)
        a[i]=(a[i-1]+a[i-2]+(i%3>0)-1)%100019;
    scanf("%d",&n);
    printf("%d",a[(n-1)%300054]);
    return 0;
}
