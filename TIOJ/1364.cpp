#include <iostream>

using namespace std;

int c[1000001], ct;

int main(){
    int i, n, k, b, lar;
    while( scanf("%d%d", &n, &k)==2 )
    {
        lar=ct=0;
        for( i=0; i<=1000000; i++ ) c[i]=0;
        while( n-- )
        {
            scanf("%d", &b);
            c[b]++;
            lar=max(lar, b);
        }
        for( i=lar; i>=0; i-- )
        {
            if( ct<k && ct+c[i]>=k )
            {
                printf("%d\n", i);
                break;
            }
            ct+=c[i];
        }
    }
    return 0;
}