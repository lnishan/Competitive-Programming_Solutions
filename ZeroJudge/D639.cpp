#include<iostream>
using namespace std;

int a[2781668],n;
int main(){
    a[0]=a[1]=a[2]=1;
    for(int i=3;i<2781668;i++)
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10007;
    scanf("%d",&n);
    printf("%d",a[(n-1)%2781668]);
    return 0;
}
