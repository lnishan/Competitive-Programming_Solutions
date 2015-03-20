#include <iostream>

using namespace std;

int main(){
    int i, n, t;
    while( scanf("%d", &n)==1 )
    {
        t=1;
        for( i=0; i<n; i++ )
        {
            t*=13;
            t%=100;
        }
        printf("%d\n", t/10);
    }
    return 0;
}
