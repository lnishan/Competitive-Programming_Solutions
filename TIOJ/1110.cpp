#include <iostream>

using namespace std;

char s[100002];
int a[123];

int main(){
    int i, t, l, ma;
    scanf("%d", &t);
    while( t-- )
    {
        ma=0;
        for( i=97; i<=122; i++ ) a[i]=0;
        scanf("%d %s", &l, &s);
        for( i=0; i<l; i++ )
            a[s[i]]++;
        for( i=97; i<=122; i++ )
            ma=max(ma, a[i]);
        for( i=97; i<=122; i++ )
            if( a[i]==ma )
                putchar(i);
        putchar('\n');
    }
    return 0;
}