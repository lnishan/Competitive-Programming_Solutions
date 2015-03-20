#include<iostream>
#include<math.h>
using namespace std;
bool a[1000001];
int pr[80000],pc=0,n,ans;
int main(){
    a[1]=a[2]=true;
    for(int i=3;i<=1000000;i++)
            if(i%2==0)a[i]=false;else a[i]=true;
    for(int i=3;i<=1000;i+=2)
            if(a[i])
                    for(int j=2;j<=1000000/i;j++)a[i*j]=false;
    for(int i=2;i<=1000000;i++)if(a[i]){pr[pc]=i;pc++;}
    while(scanf("%d",&n)&&n!=0)
    {
                               for(int i=0;;i++)
                               {
                                       if(a[n-pr[i]]){printf("%d = %d + %d\n",n,pr[i],n-pr[i]);break;}
                                       if(pr[i]*2>=n){printf("Goldbach's conjecture is wrong.\n");break;}
                               }
    }
    return 0;
}
