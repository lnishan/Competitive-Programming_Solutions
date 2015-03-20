#include<iostream>
#include<math.h>
using namespace std;
bool a[32768];
int pr[15000],pc=0,n;
int main(){
    a[1]=a[2]=true;
    for(int i=3;i<=32767;i++)
            if(i%2==0)a[i]=false;else a[i]=true;
    for(int i=3;i<=182;i+=2)
            if(a[i])
                    for(int j=2;j<=32767/i;j++)a[i*j]=false;
    for(int i=2;i<=32767;i++)if(a[i]){pr[pc]=i;pc++;}
    while(scanf("%d",&n)&&n!=0)
    {
                               int ct=0;
                               for(int i=0;;i++)
                               {
                                       if(pr[i]*2>n)break;
                                       if(a[n-pr[i]])ct++;
                               }
                               printf("%d\n",ct);
    }
    return 0;
}
