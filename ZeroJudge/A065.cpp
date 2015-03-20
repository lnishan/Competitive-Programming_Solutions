#include <cstdio>
#include <cstring>

using namespace std;

char s[10];

int main(){
    int i;
    while( gets(s) )
    {
        for( i=1; i<7; i++ )
        {
            if( s[i]>s[i-1] )
                printf("%d", s[i]-s[i-1]);
            else
                printf("%d", s[i-1]-s[i]);
        }
        putchar('\n');
    }
    return 0;
}
