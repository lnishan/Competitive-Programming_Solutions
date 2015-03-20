#include <cstdio>

using namespace std;

inline int input(){
    char c;
    for( c=getchar(); c<48||c>57; c=getchar() ) ;
    int x=c-48;
    for( c=getchar(); c>47&&c<58; c=getchar() ) ;
    return x;
}

int p[4], q[4];

int main(){
    int i, j, n, a, b;
    while( scanf("%d", &p[0])==1 )
    {
        p[1]=input(); p[2]=input(); p[3]=input();
        n=input();
        while( n-- )
        {
            a=b=0;
            q[0]=input();q[1]=input();q[2]=input();q[3]=input();
            for( i=0; i<4; i++ )
                if( p[i]==q[i] )
                {
                    a++;
                    q[i]=-1;
                    p[i]+=10;
                }
            for( i=0; i<4; i++ )
                if( q[i]>=0 )
                    for( j=0; j<4; j++ )
                        if( q[i]==p[j] )
                        {
                            b++;
                            q[i]=-1;
                            p[j]+=10;
                            break;
                        }
            printf("%dA%dB\n", a, b);
            for( i=0; i<4; i++ )
                p[i]%=10;
        }
    }
    return 0;
}
