#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int ns,a,b,mdiv,mn,tct;
    scanf("%d",&ns);
    for(int i=0;i<ns;i++)
    {
            mdiv=0;
            scanf("%d%d",&a,&b);
            for(int j=a;j<=b;j++)
            {
                    tct=0;
                    for(int k=1;k<=sqrt(j);k++) if(j%k==0)tct++;
                    tct*=2;
                    if(int(sqrt(j))==sqrt(j))tct--;
                    if(tct>mdiv){mdiv=tct;mn=j;}
            }
            printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,mn,mdiv);
    }
    return 0;
}
