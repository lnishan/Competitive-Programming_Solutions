#include <cstdio>

using namespace std;

int p[50], pc=4, a[10];

int main(){
    int i, j, n, t, m;
    p[0]=2; p[1]=3; p[2]=5; p[3]=7;
    for( i=7; i<=100; i++ )
        if( i%2 && i%3 && i%5 && i%7 )
            p[pc++]=i;
    while( scanf("%d", &n)==1 && n>0 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        m=1;
        for( i=0; i<pc; i++ )
        {
            while(1)
            {
                t=0;
                for( j=0; j<n; j++ )
                    if( a[j]%p[i]==0 )
                        t++;
                if( t>1 )
                {
                    m*=p[i];
                    for( j=0; j<n; j++ )
                        if( a[j]%p[i]==0 )
                            a[j]/=p[i];
                }
                else
                    break;
            }
        }
        for( i=0; i<n; i++ )
            m*=a[i];
        printf("%d\n", m);
    }
    return 0;
}
