#include <iostream>

using namespace std;

int main(){
    int i, n, k, t;
    char s[102];
    while( scanf("%d%d", &n, &k)==2 )
    {
        gets(s);
        t=n-k;
        for( i=0; i<n; i++ )
        {
            gets(s);
            if( i==t )
                printf("%s\n", s);
        }
    }
    return 0;
}