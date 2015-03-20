#include <iostream>

using namespace std;

int main(){
    int i, j, slen, ta, te, ans;
    char s[100];
    while( gets(s) )
    {
        ans=0;
        slen=strlen(s);
        for( i=0; i<slen; i++ )
        {
            ta=1;
            te=min(i, slen-i-1);
            for( j=1; j<=te; j++ )
                if( s[i-j]==s[i+j] )
                    ta+=2;
                else
                    break;
            ans=max(ans, ta);
        }
        for( i=1; i<slen; i++ )
        {
            ta=0;
            te=min(i, slen-i);
            for( j=0; j<te; j++ )
                if( s[i-j-1]==s[i+j] )
                    ta+=2;
                else
                    break;
            ans=max(ans, ta);
        }
        if( ans<2 )
            puts("1");
        else
            printf("%d\n", ans);
    }
    return 0;
}