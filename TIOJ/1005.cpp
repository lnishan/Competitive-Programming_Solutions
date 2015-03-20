/* 12/19/2010 */
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char s[1000];

int GCD(int a, int b){
    while( a!=0 && b!=0 )
        if( a>b )
            a%=b;
        else
            b%=a;
    return ( a==0 )? b:a;
}

int main(){
    int i, j, n, a[50], c[50], pc, slen, mn;
    c[2]=1; for( i=3; i<50; i++ ) c[i]=c[i-1]*i/(i-2);
    while( scanf("%d", &n) && n>0 )
    {
        pc=0;
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        for( i=0; i<n; i++ )
            for( j=i+1; j<n; j++ )
                if( GCD(a[i], a[j])==1 )
                    pc++;
        if( pc==0 )
            puts("No estimate for this data set.");
        else
        {
            sprintf(s, "%0.10lf", sqrt(double(c[n]*6)/pc));
            slen=strlen(s);
            for( i=0; i<slen; i++ )
            {
                putchar(s[i]);
                if( s[i]=='.' )
                {
                    n=s[i+1]-48;
                    for( j=i+2; j<i+7; j++ )
                        n=n*10+s[j]-48;
                    if( s[i+7]-48>=5 ) n++;
                    printf("%06d", n);
                    break;
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
