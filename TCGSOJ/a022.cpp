#include <iostream>

using namespace std;

int main(){
    int i, n, m;
    while( scanf("%d%d", &n, &m)==2 )
    {
        for( i=0; ; i++,n*=3 )
            if( n>=m ) break;
        printf("%d\n", i);
    }
    return 0;
}
