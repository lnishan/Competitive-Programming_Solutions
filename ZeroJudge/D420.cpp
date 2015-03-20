#include<iostream>
using namespace std;
long long int a,wa,b,tct,cct=0;
int main(){
    while(scanf("%lld%lld",&a,&b),a>0||b>0)
    {
         wa=a;tct=0;
         while(wa!=1&&wa<=b)
         {
              if(wa%2)wa=3*wa+1;else wa/=2;
              tct++;
         }
         if(wa==1)tct++;
         printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++cct,a,b,tct);
    }
    return 0;
}
