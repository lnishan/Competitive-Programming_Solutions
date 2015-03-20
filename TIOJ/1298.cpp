#include <iostream>

using namespace std;

int main(){
    double s, maxs, mins, sum;
    int i, n, win;
    while( scanf("%d", &n)==1 )
    {
        sum=win=0; maxs=-201; mins=201;
        for( i=0; i<n; i++ )
        {
            scanf("%lf", &s);
            if( s>0 ) win++; else s=-s;
            sum+=s;
            maxs=max(maxs, s);
            mins=min(mins, s);
        }
        sum=sum-maxs-mins;
        printf("Average time: %.3lf sec(s).\n", sum/(n-2));
        printf("Winning rate: %.3lf ", double(win*100)/n);
        putchar('%'); puts(".");
    }
    return 0;
}