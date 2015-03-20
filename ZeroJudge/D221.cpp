#include<iostream>
using namespace std;
int main(){
    int ns,a[5000];
    while(scanf("%d",&ns)&&ns!=0)
    {
         for(int i=0;i<ns;i++)scanf("%d",&a[i]);
         sort(a,a+ns);
         long long int c=0,c2=a[0];
         for(int i=1;i<ns;i++)
         {
                 c2+=a[i];
                 c+=c2;
         }
         printf("%lld\n",c);
    }
    return 0;
}
