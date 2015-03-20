#include <iostream>

using namespace std;

void str(int n, char c){
    while( n-- )
        putchar(c);
    return ;
}

int main(){
    int i, j, k, l, n;
    while( scanf("%d", &n) && n>0 )
    {
        for( i=1; i<n; i++ )
        {
            str(i-1, ' ');
            putchar('*');
            str(n-i-1, ' ');
            putchar('*');
            str(n-i-1, ' ');
            putchar('*');
            putchar('\n');
        }
        str(2*n-1, '*'); putchar('\n');
        for( i=n-1; i>=1; i-- )
        {
            str(i-1, ' ');
            putchar('*');
            str(n-i-1, ' ');
            putchar('*');
            str(n-i-1, ' ');
            putchar('*');
            putchar('\n');
        }
    }
    return 0;
}