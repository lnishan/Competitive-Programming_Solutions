#include <iostream>

using namespace std;

int main(){
    int i, j, n, a;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
    {
        a=i%3;
        for( j=0; j<n; j++ )
            if( (j+3-a)%3==0 )
                putchar('@');
            else
                putchar('-');
        putchar('\n');
    }
    //while(1);
    return 0;
}
