#include<iostream>
using namespace std;
int main(){
    int ns,n,gcd,ta,tb;
    while(scanf("%d",&ns)!=EOF)
    {
                               scanf("%d",&gcd);
                               for(int i=1;i<ns;i++)
                               {
                                       scanf("%d",&n);
                                       ta=gcd;tb=n;
                                       while(ta!=0&&tb!=0)if(ta>tb)ta%=tb;else tb%=ta;
                                       gcd=(ta==0)?tb:ta;
                               }
                               printf("%d\n",gcd);
    }
    return 0;
}
