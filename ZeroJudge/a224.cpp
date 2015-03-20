#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char s[1002];
int c[91];

int main(){
    int i, l, oc;
    while( gets(s) )
    {
        oc=0;
        memset(c, 0, sizeof(c));
        l=strlen(s);
        for( i=0; i<l; i++ )
            if( isalpha(s[i]) )
            {
                if( islower(s[i]) )
                    s[i]=toupper(s[i]);
                c[s[i]]++;
            }
        for( i=65; i<=90; i++ )
            if( c[i]%2 )
                oc++;
        if( oc<2 )
            puts("yes !");
        else
            puts("no...");
    }
    return 0;
}
