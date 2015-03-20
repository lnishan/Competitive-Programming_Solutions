#include <iostream>

using namespace std;

int main(){
    int i, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=n; i>=0; i-- )
        {
            printf("%d", i);
            if( i>0 ) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
