#include <iostream>

using namespace std;

int main(){
    int i, j, w, h;
    while( scanf("%d%d", &w, &h)==2 )
        for( i=0; i<h; i++ )
        {
            for( j=0; j<w; j++ )
                putchar('#');
            putchar('\n');
        }
    return 0;
}
