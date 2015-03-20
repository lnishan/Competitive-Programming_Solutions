#include<iostream>
#include<math.h>
using namespace std;
int a[1000000];
int main(){
    for(int i=3;i<1000000;i+=2)
    {
            bool prime=true;
            for(int j=2;j<=sqrt(i);j++){if(i%j==0){prime=false;break;}}
            if(prime)a[i]=1;else a[i]=0;
    }
    int n;
    while(scanf("%d",&n) && n!=0)
    {
                         for(int i=3;i<n;i+=2){ if(a[i]==1&&a[n-i]==1){printf("%d = %d + %d\n",n,i,n-i);break;}else if(i==n-1){printf("Goldbach's conjecture is wrong.\n");} }
    }
    return 0;
}
