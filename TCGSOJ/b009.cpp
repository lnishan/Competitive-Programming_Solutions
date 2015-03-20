#include <iostream>

using namespace std;

char a[10000], b[10000];

int main(){
    int i, j, al, bl;
    while( scanf("%s %s", &a, &b)==2 )
    {
        al=strlen(a);
        bl=strlen(b);
        for( i=0,j=0; i<al&&j<bl; j++ )
            if( a[i]==b[j] ) i++;
        if( i==al )
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
