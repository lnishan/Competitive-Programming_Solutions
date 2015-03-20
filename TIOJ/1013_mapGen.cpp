#include <iostream>

using namespace std;

int main(){
    char s[20];
    int i=0, j, l;
    freopen("1013.txt", "w", stdout);
    while( gets(s) )
    {
        l=strlen(s);
        for( j=0; j<l; j++ )
        {
            if( s[j]=='*' )
                printf("map[%d][%d]=-1;", i, j);
            else if( s[j]=='.' )
                printf("map[%d][%d]=0;", i, j);
        }
        putchar('\n');
        i++;
    }
    return 0;
}