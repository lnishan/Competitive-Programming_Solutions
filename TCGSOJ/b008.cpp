#include <iostream>

using namespace std;

char s[1000];
int main(){
    int i, l;
    char v=1;
    while( gets(s) )
    {
        l=strlen(s);
        for( i=0; i<l/2; i++ )
            if( s[i]!=s[l-i-1] )
            {
                v=0;
                break;
            }
        if( v )
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
