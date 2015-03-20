#include <iostream>

using namespace std;

short a[10000001];
int main(){
    int i, j, n, r, d, p, maxd;
    while( scanf("%d", &n)==1 && n>0 )
    {
        a[0]=0; maxd=0;
        for( i=0; i<n; i++ )
        {
            scanf("%d%d%d", &r, &d, &p);
            if( d>maxd )
            {
                for( j=maxd+1; j<=d; j++ )
                    a[j]=a[maxd];
                maxd=d;
            }
            for( j=d; j>=r+p-1; j-- )
                if( a[j-p]+1>a[j] )
                    a[j]=a[j-p]+1;
        }
        printf("%d\n", a[maxd]);
    }
    return 0;
}