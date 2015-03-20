#include <iostream>

using namespace std;

int main(){
    int n, i, a, b, c, d, ans=0;
    long long int t;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for( n=a; n<=d; n+=b )
    {
        t=1;
        for( i=0; i<c; i++ )
            t*=n, t%=1000000;
        ans+=t;
        ans%=1000000;
    }
    printf("%d", ans);
    //while(1);
    return 0;
}