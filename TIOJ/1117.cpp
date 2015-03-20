#include <iostream>

using namespace std;

int getN(int n, int i, int j){
    if( n==0 ) return -1;
    int t=1<<(n-1);
    if( i>=t && j>=t )
        return -getN(n-1, i%t, j%t);
    else
        return getN(n-1, i%t, j%t);
}

int main(){
    int j, n, i, a, b;
    while( scanf("%d%d%d%d", &n, &i, &a, &b)==4 )
    {
        printf("%+d", getN(n, i-1, a-1));
        for( j=a+1; j<=b; j++ )
            printf(" %+d", getN(n, i-1, j-1));
        putchar('\n');
    }
    return 0;
}