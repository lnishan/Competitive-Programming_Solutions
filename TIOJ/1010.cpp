#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[1002], s2[1002];

int main(){
    int i, j, l1, l2, ml;
    bool same, printed=false;
    gets(s1);
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    ml=min(l1, l2);
    for( i=ml; i>=1; i-- )
    {
        same=true;
        for( j=1; j<=i; j++ )
            if( s1[j-1]!=s2[l2-i+j-1] )
            {
                same=false;
                break;
            }
        if( same )
        {
            printf("%d", i);
            printed=true;
            break;
        }
    }
    if( !printed )
        putchar('0');
    //while(1);
    return 0;
}
