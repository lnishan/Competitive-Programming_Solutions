#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

char s[1002], v;

int main(){
    int i, t, l;
    long long int x, y, z, w, n, m, poi;
    scanf("%d", &t);
    while( t-- )
    {
        v=1;
        poi=0;
        scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &z, &w, &n, &m);
        gets(s);
        gets(s);
        l=strlen(s);
        for( i=0; i<l; i++ )
        if( isdigit(s[i]) )
        {
            m-=poi;
            if( m<=0 )
            {
                v=0;
                break;
            }
            if( s[i]=='1' )
                m+=x;
            else if( s[i]=='2' )
                m+=y;
            else if( s[i]=='3' )
                m-=z;
            else if( s[i]=='4' )
                m-=w, poi+=n;
            if( m<=0 )
            {
                v=0;
                break;
            }
        }
        if( v )
            printf("%lldg\n", m);
        else    
            puts("bye~Rabbit");
    }
    return 0;
}
