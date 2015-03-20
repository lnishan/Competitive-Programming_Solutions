#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    if( a%10!=b%10 )
        return a%10 < b%10;
    else
        return a>b;
}

int a[1000];

int main(){
    int i, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        sort(a, a+n, cmp);
        for( i=0; i<n; i++ )
        {
            if( i>0 ) putchar(' ');
            printf("%d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}
