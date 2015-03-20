#include<iostream>

using namespace std;

int t,a,b,c;

int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if( (c>=a&&a>=b) || (c<=a&&a<=b) )
            printf("Case %d: %d\n",i,a);
        else if( (a>=b&&b>=c) || (a<=b&&b<=c) )
            printf("Case %d: %d\n",i,b);
        else
            printf("Case %d: %d\n",i,c);
    }
    return 0;
}
