#include <iostream>

using namespace std;

int n,b[5]={6,8,4,2},c[10]={1,1,2,6,4,2,2,4,2,8},a[10001];

int main(){
    int i;
    a[0]=1;
    for(i=1;i<10001;i++)
    {
        a[i]=a[i-1]*i;
        while(a[i]%10==0) a[i]/=10;
        a[i]%=10;
    }
    for(i=1;i<301;i++)
    {
        n=(b[(i/10)%4]*c[i%10])%10;
        if(n!=a[i])
            printf("Wrong ! number : %d , Output: %d , Correct: %d.\n",i,n,a[i]);
    }
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",(b[(n/10)%4]*c[n%10])%10);
        printf("Correct : %d\n",a[n]);
    }
    return 0;
}