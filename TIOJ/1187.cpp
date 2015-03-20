#include <iostream>

using namespace std;

int main(){
    int i, n, sum, sc, l, h;
    while( scanf("%d", &n) && n>0 )
    {
        sum=0;
        l=11; h=-1;
        for( i=0; i<n; i++ )
        {
            scanf("%d", &sc);
            l=min(l, sc);
            h=max(h, sc);
            sum+=sc;
        }
        sum=sum-l-h;
        printf("%.2lf\n", double(sum)/(n-2)+1e-6);
    }
    return 0;
}