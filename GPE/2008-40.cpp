#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[50];

int main(){
    unsigned long long int f[94];  // 93
    int i, sz=2, n;
    f[0]=0; f[1]=1;
    for( i=2; i<94; i++ )
        f[i]=f[i-1]+f[i-2];
    while( gets(s) && strlen(s)>1 )
    {
        n=s[9]-48;
        for( i=10; s[i]!=')'; i++ )
            n=n*10+s[i]-48;
        putchar('[');
        for( i=0; i<n; i++ )
        {
            if( i>0 ) putchar(',');
            printf("%d", f[i]);
        }
        printf("] create %d nodes\n", max(sz, n)-sz);
        sz=max(sz, n);
    }
    return 0;
}
