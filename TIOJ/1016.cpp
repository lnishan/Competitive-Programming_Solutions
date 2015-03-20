#include <cstdio>
#include <cstring>

using namespace std;

char s[10000];
int main(){
    int i, j, t, c[2], b[4], o, l, a;
    while( gets(s) )
    {
        t=c[0]=c[1]=b[0]=b[1]=b[2]=b[3]=o=0;
        l=strlen(s);
        for( i=0; i<l; i++ )
            if( s[i]=='O' || s[i]=='K' )
            {
                if( ++o==3 )
                {
                    t=1-t;
                    b[0]=b[1]=b[2]=b[3]=o=0;
                }
            }
            else if( s[i]=='W' )
            {
                b[1]++;
                for( j=1; j<=3; j++ )
                    if( b[j]>1 )
                    {
                        b[j]=1;
                        if( j==3 ) c[t]++; else b[j+1]++;
                    }
            }
            else
            {
                b[0]=1;
                if( s[i]=='S' ) a=1;
                else if( s[i]=='D' ) a=2;
                else if( s[i]=='T' ) a=3;
                else if( s[i]=='H' ) a=4;
                for( j=3; j>=0; j-- )
                    if( b[j] )
                    {
                        b[j]=0;
                        if( j+a>3 )
                            c[t]++;
                        else
                            b[j+a]=1;
                    }
            }
        printf("%d %d\n", c[0], c[1]);
    }
    return 0;
}
