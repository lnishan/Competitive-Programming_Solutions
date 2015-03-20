#include <cstdio>
#include <cstring>

char s[12];

int main(){
    int i, t, l;
    long long int m;
    scanf("%d", &t);
    scanf("\n");
    while( t-- )
    {
        m=1;
        gets(s);
        l=strlen(s);
        for( i=0; i<l; i++ )
            m*=s[i]-48;
        printf("%lld\n", m);
    }
    return 0;
}
